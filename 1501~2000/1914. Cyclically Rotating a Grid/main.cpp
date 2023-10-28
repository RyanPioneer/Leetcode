/**
 * Source: tinyurl.com/yudlk2kn
 * Date: 2023/10/28
 * Skill:
 * Runtime: 11 ms, faster than 97.01% of C++ online submissions
 * Memory Usage: 12.83 MB, less than 65.67% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        int nums[200];
        int h = m, w = n, time = min(m, n) / 2;
        for (int i = 0; i < time; i++) {
            int x = i, y = i, len = (h + w) * 2 - 4;
            int r = k % len, idx = 0;
            for (int j = 1; j < h; j++) nums[idx++] = grid[x++][y];
            for (int j = 1; j < w; j++) nums[idx++] = grid[x][y++];
            for (int j = 1; j < h; j++) nums[idx++] = grid[x--][y];
            for (int j = 1; j < w; j++) nums[idx++] = grid[x][y--];
            idx = 0;
            for (int j = 1; j < h; j++, idx++) res[x++][y] = nums[(idx - r + len) % len];
            for (int j = 1; j < w; j++, idx++) res[x][y++] = nums[(idx - r + len) % len];
            for (int j = 1; j < h; j++, idx++) res[x--][y] = nums[(idx - r + len) % len];
            for (int j = 1; j < w; j++, idx++) res[x][y--] = nums[(idx - r + len) % len];
            h -= 2;
            w -= 2;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1,0,1,2,1};
}