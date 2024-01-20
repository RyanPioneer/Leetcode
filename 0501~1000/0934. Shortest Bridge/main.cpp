/**
 * Source: jpeg.ly/nzzwN
 * Date: 2024/1/20
 * Skill:
 * Ref:
 * Runtime: 34 ms, faster than 80.23% of C++ online submissions
 * Memory Usage: 22.85 MB, less than 34.78% of C++ online submissions
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
typedef pair<int, int> PII;
const int MX = 100;


class Solution {
    int m, n;
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int res = INT32_MAX, visited[MX][MX] = {0}, dir[5] = {0, 1, 0, -1, 0};
        m = SZ(grid), n = SZ(grid[0]);
        vector<vector<PII>> land;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = 1;
                    queue<PII> q;
                    q.push({i, j});
                    vector<PII> v;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        if (is_board(x, y, grid)) v.push_back({x, y});
                        for (int k = 0; k < 4; k++) {
                            int xx = x + dir[k], yy = y + dir[k + 1];
                            if (!check(xx, yy)) continue;
                            if (grid[xx][yy] == 1 && !visited[xx][yy]) {
                                visited[xx][yy] = 1;
                                q.push({xx, yy});
                            }
                        }
                    }
                    land.push_back(v);
                }
            }
        }
        for (auto &p1: land[0]) {
            for (auto &p2: land[1]) {
                res = min(res, abs(p1.first - p2.first) + abs(p1.second - p2.second));
            }
        }
        return res - 1;
    }
    bool is_board(int x, int y, vector<vector<int>>& grid) {
        if (x == 0 || x == m - 1) return true;
        if (y == 0 || y == n - 1) return true;
        return !(grid[x - 1][y] && grid[x + 1][y] && grid[x][y - 1] && grid[x][y + 1]);
    }
    bool check(int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
};