/**
 * Source: ibit.ly/LLx6g
 * Date: 2023/10/31
 * Skill:
 * Runtime: 18 ms, faster than 86.47% of C++ online submissions
 * Memory Usage: 9.79 MB, less than 77.44% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 50
 */


const int MX = 52;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 1;
        int rows[MX][MX], cols[MX][MX], dig1[MX][MX], dig2[MX][MX];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i + 1][j + 1] = rows[i + 1][j] + grid[i][j];
                cols[i + 1][j + 1] = cols[i][j + 1] + grid[i][j];
                dig1[i + 1][j + 1] = dig1[i][j] + grid[i][j];
                dig2[i + 1][j + 1] = dig2[i][j + 2] + grid[i][j];
            }
        }
        for (int len = 2; len <= min(m, n); len++) {
            bool find = false;
            for (int i = 0; i + len <= m; i++) {
                if (find) break;
                for (int j = 0; j + len <= n; j++) {
                    if (find) break;
                    int sum = dig1[i + len][j + len] - dig1[i][j];
                    bool match = sum == dig2[i + len][j + 1] - dig2[i][j + 1 + len];
                    for (int k = 0; k < len; k++) {
                        int num = rows[k][j + len] - rows[k][j];
                        match &= sum == rows[i + 1 + k][j + len] - rows[i + 1 + k][j];
                        match &= sum == cols[i + len][j + 1 + k] - cols[i][j + 1 + k];
                    }
                    if (!match) continue;
                    res = len;
                    find = true;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}