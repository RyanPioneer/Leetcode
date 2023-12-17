/**
 * Source: https://rb.gy/n86qa
 * Date: 2023/12/14
 * Skill:
 * Ref:
 * Runtime: 185 ms, faster than 82.16% of C++ online submissions
 * Memory Usage: 116.77 MB, less than 85.57% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        int rows[MX] = {0}, cols[MX] = {0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] += grid[i][j] == 1 ? 1 : -1;
                cols[j] += grid[i][j] == 1 ? 1 : -1;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = rows[i] + cols[j];
            }
        }
        return res;
    }
};