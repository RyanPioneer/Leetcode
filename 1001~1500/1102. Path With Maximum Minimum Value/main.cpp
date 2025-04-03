/**
 * Source: t.ly/G9xEe
 * Date: 2025/4/3
 * Skill:
 * Ref:
 * Runtime: 157 ms, faster than 69.11% of C++ online submissions
 * Memory Usage: 49.22 MB, less than 65.85% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
const int MX = 100;

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int par[MX * MX];
        iota(par, par + MX * MX, 0);

        function<int(int)> find = [&](int x) {
            return par[x] == x ? x : par[x] = find(par[x]);
        };

        auto unionSet = [&](int x, int y) {
            par[find(x)] = find(y);
        };

        auto check = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        vector<int> dirs = { 0, 1, 0, -1, 0 };
        vector<array<int, 3>> vec;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vec.push_back({ grid[i][j], i, j });
            }
        }
        sort(vec.begin(), vec.end(), greater<array<int, 3>>());
        for (auto& v : vec) {
            int val = v[0], x = v[1], y = v[2];
            int idx = x * MX + y;
            for (int i = 0; i < 4; i++) {
                int xx = x + dirs[i], yy = y + dirs[i + 1];
                int idx2 = xx * MX + yy;
                if (check(xx, yy) && visited[xx][yy] && find(idx) != find(idx2)) {
                    unionSet(idx, idx2);
                }
            }
            visited[x][y] = 1;
            if (find(0) == find((m - 1) * MX + (n - 1))) {
                return val;
            }
        }
        return 0;
    }
};
