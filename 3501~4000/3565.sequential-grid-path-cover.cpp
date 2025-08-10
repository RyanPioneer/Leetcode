/*
 * @lc app=leetcode id=3565 lang=cpp
 *
 * [3565] Sequential Grid Path Cover
 */

// @lc code=start
const int MX = 6;
class Solution {
   public:
    vector<vector<int>> findPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), num = 0;
        int total = m * n, dirs[5] = {0, 1, 0, -1, 0};
        int visited[MX][MX] = {0};
        vector<vector<int>> res;

        auto checkFeasible = [&](int x, int y) {
            return 0 <= x && x < m && 0 <= y && y < n && !visited[x][y];
        };

        function<bool(int, int, int)> dfs = [&](int x, int y, int nextOrder) {
            if (!checkFeasible(x, y)) return false;
            if (grid[x][y] != 0 && grid[x][y] != nextOrder) return false;
            if (++num == total) {
                res.push_back({x, y});
                return true;
            }
            nextOrder = grid[x][y] != nextOrder ? nextOrder : nextOrder + 1;
            visited[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (dfs(nx, ny, nextOrder)) {
                    res.push_back({x, y});
                    return true;
                }
            }
            num--;
            visited[x][y] = 0;
            return false;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 1)) {
                    break;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
