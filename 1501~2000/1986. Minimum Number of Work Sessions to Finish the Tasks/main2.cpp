/**
 * Source: https://rb.gy/rr1qd
 * Date: 2023/8/28
 * Skill:
 * Runtime: 351 ms, faster than 54.64% of C++ online submissions
 * Memory Usage: 9.54 MB, less than 63.91% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= tasks.length <= 14
 *      1 <= tasks[i] <= 10
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        vector<int> dp(1 << tasks.size(), INT32_MAX / 2);
        for (int i = 0; i < (1 << tasks.size()); i++) {
            int sum = 0;
            for (int j = 0; j < tasks.size(); j++) {
                if ((i >> j) & 1)
                    sum += tasks[j];
            }
            if (sum <= sessionTime)
                dp[i] = 1;
        }
        for (int i = 1; i < (1 << tasks.size()); i++) {
            if (dp[i] != INT32_MAX / 2)
                continue;
            int num = INT32_MAX;
            for (int j = i; j > 0; j = (j - 1) & i) {
                num = min(num, dp[j] + dp[i - j]);
            }
            dp[i] = num;
        }
        return dp[(1 << tasks.size()) - 1];
    }
};

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();

int main() {
    Solution s;
    vector<int> tasks = {3, 1};
    int sessionTime = 7;
    int res = s.minSessions(tasks, sessionTime);
    cout << res;
}