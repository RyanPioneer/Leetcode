/**
 * Source: jpeg.ly/CTx2O
 * Date: 2023/12/4
 * Skill:
 * Ref:
 * Runtime: 20 ms, faster than 80.22% of C++ online submissions
 * Memory Usage: 11.78 MB, less than 82.42% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= m, n <= 50
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
#define x first
#define y second
typedef pair<int, int> PII;
const int MX = 50;


class Solution {
    int visited[MX][MX], dir[5] = {0, 1, 0, -1, 0}, m, n;
public:
    int containVirus(vector<vector<int>>& isInfected) {
        m = SZ(isInfected), n = SZ(isInfected[0]);
        int res = 0;
        while (true) {
            fill(visited[0], visited[MX - 1] + MX, 0);
            int cur_max = 0, x, y;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isInfected[i][j] == 0 || isInfected[i][j] == -1 || visited[i][j]) continue;
                    int num = cal(isInfected, i, j);
                    if (num > cur_max) {
                        cur_max = num;
                        x = i;
                        y = j;
                    }
                }
            }
            if (cur_max == 0) return res;
            res += build_wall(isInfected, x, y);
            spread(isInfected);
        }
        return res;
    }
    int cal(vector<vector<int>>& isInfected, int x, int y) {
        unordered_set<int> grid;
        queue<PII> q;
        q.push({x, y});
        visited[x][y] = 1;
        int num = 0;
        while (!q.empty()) {
            auto [xx, yy] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x1 = xx + dir[i], y1 = yy + dir[i + 1];
                if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) continue;
                if (isInfected[x1][y1] == -1 || visited[x1][y1] == 1) continue;
                if (isInfected[x1][y1] == 1) {
                    q.push({x1, y1});
                    visited[x1][y1] = 1;
                } else if (grid.find(x1 * MX + y1) == end(grid)) {
                    grid.insert(x1 * MX + y1);
                    num++;
                }
            }
        }
        return num;
    }
    int build_wall(vector<vector<int>>& isInfected, int x, int y) {
        int num = 0;
        queue<PII> q;
        q.push({x, y});
        isInfected[x][y] = -1;
        while (!q.empty()) {
            auto [xx, yy] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x1 = xx + dir[i], y1 = yy + dir[i + 1];
                if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) continue;
                if (isInfected[x1][y1] == -1) continue;
                if (isInfected[x1][y1] == 1) {
                    q.push({x1, y1});
                    isInfected[x1][y1] = -1;
                } else if (isInfected[x1][y1] == 0) {
                    num++;
                }
            }
        }
        return num;
    }
    void spread(vector<vector<int>>& isInfected) {
        queue<PII> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isInfected[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [xx, yy] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x1 = xx + dir[i], y1 = yy + dir[i + 1];
                if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) continue;
                if (isInfected[x1][y1] == 0) isInfected[x1][y1] = 1;
            }
        }
    }
};