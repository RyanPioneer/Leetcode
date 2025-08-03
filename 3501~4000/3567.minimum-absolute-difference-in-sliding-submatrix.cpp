/*
 * @lc app=leetcode id=3567 lang=cpp
 *
 * [3567] Minimum Absolute Difference in Sliding Submatrix
 */

// @lc code=start
#define PII pair<int, int>
class Solution {
   public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1, INT_MAX));
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                set<int> nums;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        auto it = nums.upper_bound(grid[x][y]);
                        if (it != nums.end()) {
                            res[i][j] = min(res[i][j], *it - grid[x][y]);
                        }
                        it = nums.lower_bound(grid[x][y]);
                        if (it != nums.begin()) {
                            it--;
                            res[i][j] = min(res[i][j], grid[x][y] - *it);
                        }
                        if (nums.find(grid[x][y]) == nums.end())
                            nums.insert(grid[x][y]);
                    }
                }
                if (res[i][j] == INT_MAX) {
                    res[i][j] = 0;  // If no valid difference found, set to -1
                }
            }
        }
        return res;
    }
};
// @lc code=end
