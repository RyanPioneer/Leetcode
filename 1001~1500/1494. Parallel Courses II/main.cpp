/**
 * Source: https://rb.gy/uwwmb
 * Date: 2023/9/1
 * Skill:
 * Runtime: 440 ms, faster than 42.91% of C++ online submissions
 * Memory Usage: 10.38 MB, less than 86.57% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> dp(1 << n, INT32_MAX / 2);
        dp[0] = 0;
        vector<int> prereq(n, 0);
        for (auto i: relations)
            prereq[i[1] - 1] += (1 << (i[0] - 1));
        for (int state = 1; state < (1 << n); state++) {
            int count = __builtin_popcount(state), pre_reqs = 0;
            for (int i = 0; i < n; i++) {
                if ((state >> i) & 1 != 0)
                    pre_reqs |= prereq[i];
            }
            for (int substate = state; substate >= 0; substate = (substate - 1) & state) {
                if (count - __builtin_popcount(substate) <= k && (substate & pre_reqs) == pre_reqs)
                    dp[state] = min(dp[state], dp[substate] + 1);
                if (substate == 0)
                    break;
            }
        }
        return dp[(1 << n) - 1];
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> relations{{2, 1}, {3, 1}, {4, 1}, {1, 5}};
    int res = s.minNumberOfSemesters(4, relations, 2);
    cout << res << endl;

}