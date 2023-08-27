/**
 * Source: https://rb.gy/rr1qd
 * Date: 2023/8/27
 * Skill:
 * Runtime: WA
 * Memory Usage:
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
        int res = 0;
        multiset<int> nums;
        for (int task: tasks) {
            nums.insert(task);
        }
        while (nums.size() > 0) {
            res += 1;
            int rem = sessionTime;
            while (nums.size() > 0 and rem >= *nums.begin()) {
                if (rem <= *(prev(nums.end()))) {
                    auto pos = lower_bound(nums.begin(), nums.end(), rem);
                    if (*pos > rem)
                        pos = prev(pos);
                    rem -= *pos;
                    nums.erase(pos);
                } else {
                    rem -= *prev(nums.end());
                    nums.erase(prev(nums.end()));
                }
            }
        }
        return res;
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