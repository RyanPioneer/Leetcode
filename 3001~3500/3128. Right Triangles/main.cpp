/**
 * Source: tinyurl.com/26o4oyyc
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 224 ms, faster than 87.50% of C++ online submissions
 * Memory Usage: 113.77 MB, less than 25.00% of C++ online submissions
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
#define ll long long

using namespace std;

const int MX = 1e3+10;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        ll res = 0;
        int m = grid.size(), n = grid[0].size();
        int rows[MX] = {0}, cols[MX] = {0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[j] += grid[i][j];
                cols[i] += grid[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    res += (rows[j] - 1) * (cols[i] - 1);
                }
            }
        }
        return res;
    }
};