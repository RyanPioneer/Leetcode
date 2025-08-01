/*
 * @lc app=leetcode id=3619 lang=cpp
 *
 * [3619] Count Islands With Total Value Divisible by K
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), res = 0,
            dirs[5] = {0, 1, 0, -1, 0};

        auto check = [&](int x, int y) {
            return 0 <= x && x < m && 0 <= y && y < n;
        };

        function<int(int, int)> dfs = [&](int x, int y) {
            ll num = grid[x][y];
            grid[x][y] = -1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (check(nx, ny) && grid[nx][ny] > 0) {
                    num += dfs(nx, ny);
                }
            }
            return num;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    ll total = dfs(i, j);
                    if (total % k == 0) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end
