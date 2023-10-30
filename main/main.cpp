/**
 * Source: ibit.ly/LLx6g
 * Date: 2023/10/30
 * Skill:
 * Runtime: 1264 ms, faster than 5.25% of C++ online submissions
 * Memory Usage: 202.71 MB, less than 5.54% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 50
 */

#include "utilities.h"
#include "utilities.cpp"

const int MX = 51;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rows[MX][MX], cols[MX][MX], dig1[MX][MX], dig2[MX][MX];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i][j + 1] = rows[i][j] + grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cols[i][j + 1] = cols[i][j] + grid[j][i];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cols[i][j + 1] = cols[i][j] + grid[j][i];
            }
        }
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}