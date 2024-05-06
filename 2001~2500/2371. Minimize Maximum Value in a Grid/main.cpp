/**
 * Source: t.ly/ErTMK
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 215 ms, faster than 30.86% of C++ online submissions
 * Memory Usage: 49.80 MB, less than 33.33% of C++ online submissions
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

#define ll long long
typedef array<int, 3> AI3;
const int MX = 1e3+2;


class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        int row[MX], col[MX];

        fill(row, row + MX, -1);
        fill(col, col + MX, -1);

        priority_queue<AI3, vector<AI3>, greater<AI3>> pq;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.push({grid[i][j], i, j});
            }
        }

        while (!pq.empty()) {
            auto [num, x, y] = pq.top();
            pq.pop();
            int i = 1;
            if (row[x] != -1) {
                i = res[x][row[x]] + (grid[x][row[x]] < grid[x][y]);
            }
            row[x] = y;
            if (col[y] != -1) {
                i = max(i, res[col[y]][y] + (grid[col[y]][y] < grid[x][y]));
            }
            col[y] = x;
            res[x][y] = i;
        }
        return res;
    }
};