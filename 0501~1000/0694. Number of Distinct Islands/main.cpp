/**
 * Source: ibit.ly/Ama-s
 * Date: 2025/4/14
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 70.40% of C++ online submissions
 * Memory Usage: 32.40 MB, less than 92.22% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= m, n <= 50
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

const int dirs[6] = {0, 0, 1, 0, -1, 0};

class Solution {
   public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int power = max(m, n) + 1;
        unordered_set<string> islands;
        string island;

        function<void(int, int, int)> dfs = [&](int x, int y, int d) {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return;
            grid[x][y] = 0;
            island += to_string(d);
            for (int dir = 1; dir <= 4; ++dir)
                dfs(x + dirs[dir], y + dirs[dir + 1], dir);
            island += to_string(d);
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    dfs(i, j, 0);
                    islands.insert(island);
                    island.clear();
                }
        return islands.size();
    }
};
