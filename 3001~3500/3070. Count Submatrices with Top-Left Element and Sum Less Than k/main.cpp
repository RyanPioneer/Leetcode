/**
 * Source: is.gd/MghYqZ
 * Date: 2024/3/3
 * Skill:
 * Ref:
 * Runtime: 185 ms, faster than 30.00% of C++ online submissions
 * Memory Usage: 88.99 MB, less than 20.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= m, n <= 1000
 *      0 <= grid[i][j] <= 1000
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
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), res = grid[0][0] <= k ? 1 : 0;
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
            if (grid[i][0] <= k) res++;
        }
        for (int i = 1; i < n; ++i) {
            grid[0][i] += grid[0][i - 1];
            if (grid[0][i] <= k) res++;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j- 1];
                if (grid[i][j] <= k) res++;
            }
        }
        return res;
    }
};