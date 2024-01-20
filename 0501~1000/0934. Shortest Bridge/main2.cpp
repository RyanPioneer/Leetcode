/**
 * Source: jpeg.ly/nzzwN
 * Date: 2024/1/20
 * Skill:
 * Ref:
 * Runtime: 29 ms, faster than 94.67% of C++ online submissions
 * Memory Usage: 21.38 MB, less than 50.86% of C++ online submissions
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
        int dis = -1, dir[5] = {0, 1, 0, -1, 0};
        m = SZ(grid), n = SZ(grid[0]);
        bool found = false;
        queue<PII> q;
        for (int i = 0; i < m; i++) {
            if (found) break;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue<PII> q2;
                    q2.push({i, j});
                    grid[i][j] = 2;
                    while (!q2.empty()) {
                        auto [x, y] = q2.front();
                        q2.pop();
                        q.push({x, y});
                        for (int k = 0; k < 4; k++) {
                            int xx = x + dir[k], yy = y + dir[k + 1];
                            if (check(xx, yy) && grid[xx][yy] == 1) {
                                q2.push({xx, yy});
                                grid[xx][yy] = 2;
                            }
                        }
                    }
                    found = true;
                    break;
                }
            }
        }
        while (!q.empty()) {
            int sz = SZ(q);
            dis++;
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int xx = x + dir[k], yy = y + dir[k + 1];
                    if (check(xx, yy) && grid[xx][yy] != 2) {
                        if (grid[xx][yy] == 1) return dis;
                        q.push({xx, yy});
                        grid[xx][yy] = 2;
                    }
                }
            }
        }
        return dis;
    }
    bool check(int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
};