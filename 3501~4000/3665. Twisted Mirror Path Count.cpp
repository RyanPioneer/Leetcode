/*
 * @lc app=leetcode id=3665 lang=cpp
 *
 * [3665] Twisted Mirror Path Count
 */

// @lc code=start
#define ll long long
const int MOD = 1e9 + 7;
class Solution {
   public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m + 2, vector<vector<int>>(n + 2, vector<int>(2, 0)));
        dp[1][1][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i - 1][j - 1] == 0) {
                    if (i + 1 <= m) {
                        dp[i + 1][j][0] =
                            (dp[i + 1][j][0] + dp[i][j][0] + dp[i][j][1]) % MOD;
                    }
                    if (j + 1 <= n) {
                        dp[i][j + 1][1] =
                            (dp[i][j + 1][1] + dp[i][j][0] + dp[i][j][1]) % MOD;
                    }
                } else {
                    if (i + 1 <= m) {
                        dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][1]) % MOD;
                    }
                    if (j + 1 <= n) {
                        dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i][j][0]) % MOD;
                    }
                }
            }
        }
        return (dp[m][n][0] + dp[m][n][1]) % MOD;
    }
};
// @lc code=end
