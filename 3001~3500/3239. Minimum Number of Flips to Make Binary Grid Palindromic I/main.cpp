/**
 * Source: jpeg.ly/k_-wh
 * Date: 2025/1/16
 * Skill:
 * Ref:
 * Runtime: 8 ms, faster than 54.49% of C++ online submissions
 * Memory Usage: 181.78 MB, less than 80.45% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rowNum = 0, colNum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n/2; j++) {
                rowNum += grid[i][j] != grid[i][n - 1 - j];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m/2; i++) {
                colNum += grid[i][j] != grid[m - 1 - i][j];
            }
        }
        return min(rowNum, colNum);
    }
};
