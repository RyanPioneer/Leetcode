/**
 * Source: ibit.ly/RoAs5
 * Date: 2023/11/6
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 10.07 MB, less than 91.28% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 15;

#define ll long long


class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const ll mod = 1e9+7;
        const int m = grid.size(), n = grid[0].size();
        ll dp[MX][2], dp2[MX][2];
        dp[0][0] = dp[0][1] = grid[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (grid[0][i] >= 0 ? dp[i - 1][0] : dp[i - 1][1]) * grid[0][i];
            dp[i][1] = (grid[0][i] >= 0 ? dp[i - 1][1] : dp[i - 1][0]) * grid[0][i];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                dp2[j][0] = dp[j][0];
                dp2[j][1] = dp[j][1];
            }
            dp[0][0] = (grid[i][0] >= 0 ? dp2[0][0] : dp2[0][1]) * grid[i][0];
            dp[0][1] = (grid[i][0] >= 0 ? dp2[0][1] : dp2[0][0]) * grid[i][0];
            for (int j = 1; j < n; j++) {
                ll mx = max(dp[j - 1][1], dp2[j][1]);
                ll mi = min(dp[j - 1][0], dp2[j][0]);
                dp[j][0] = (grid[i][j] >= 0 ? mi : mx) * grid[i][j];
                dp[j][1] = (grid[i][j] >= 0 ? mx : mi) * grid[i][j];
            }
        }
        return dp[n - 1][1] >= 0 ? dp[n - 1][1] % mod : -1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{-1,-2,-3}, {-2,-3,-3},{-3,-3,-2}};
    ll res = s.maxProductPath(arr);
    vector<int> nums{0, 1};
}