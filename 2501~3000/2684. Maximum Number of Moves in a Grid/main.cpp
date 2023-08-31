/**
 * Source: https://rb.gy/rr4mm
 * Date: 2023/8/31
 * Skill:
 * Runtime: 158 ms, faster than 95.05% of C++ online submissions
 * Memory Usage: 62.61 MB, less than 89.93% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= m, n <= 1000
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<bool> dp(m, true);
        for (int i = 1; i < n; i++) {
            int num = 0;
            vector<bool> dp2 = dp;
            if ((dp2[0] && grid[0][i - 1] < grid[0][i]) || (dp2[1] && grid[1][i - 1] < grid[0][i])) {
                dp[0] = true;
                num++;
            } else
                dp[0] = false;
            if ((dp2[m - 1] && grid[m - 1][i - 1] < grid[m - 1][i]) || (dp2[m - 2] && grid[m - 2][i - 1] < grid[m - 1][i])) {
                dp[m - 1] = true;
                num++;
            } else
                dp[m - 1] = false;
            for (int j = 1; j < m - 1; j++) {
                if ((dp2[j - 1] && grid[j - 1][i - 1] < grid[j][i]) ||  (dp2[j] && grid[j][i - 1] < grid[j][i]) || (dp2[j + 1] && grid[j + 1][i - 1] < grid[j][i])) {
                    dp[j] = true;
                    num++;
                } else
                    dp[j] = false;
            }
            if (num == 0)
                return i - 1;
        }
        return n - 1;
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
    vector<vector<int>> arr{{3,2,4},{2,1,9},{1,1,7}};
    int res = s.maxMoves(arr);
    cout << res << endl;
}