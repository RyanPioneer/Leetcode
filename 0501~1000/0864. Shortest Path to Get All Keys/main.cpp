/**
 * Source: is.gd/D3ecYG
 * Date: 2023/11/25
 * Skill:
 * Ref:
 * Runtime: 19 ms, faster than 91.39% of C++ online submissions
 * Memory Usage: 10.54 MB, less than 82.78% of C++ online submissions
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
#define MK(X, Y) make_pair(X, Y)
typedef pair<int, int> PII;
const int MX = 30;


class Solution {
    int m, n;
public:
    int shortestPathAllKeys(vector<string>& grid) {
        m = SZ(grid), n = SZ(grid[0]);
        int visited[MX][MX][1 << 6], dir[5] = {0, 1, 0, -1, 0}, key_number = 0;
        fill(visited[0][0], visited[MX - 1][MX - 1] + (1 << 6), -1);
        PII start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    start = MK(i, j);
                } else if (isalpha(grid[i][j])) {
                    key_number++;
                }
            }
        }
        key_number /= 2;
        int state = 0, final_state = (1 << key_number) - 1;
        queue<pair<PII, int>> q;
        q.push(MK(start, state));
        visited[start.first][start.second][0] = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [pos, cur_state] = q.front();
                q.pop();
                if (cur_state == final_state) return visited[pos.first][pos.second][cur_state];
                for (int i = 0; i < 4; ++i) {
                    int xx = pos.first + dir[i], yy = pos.second + dir[i + 1];
                    if (!check_boundary(xx, yy) || grid[xx][yy] == '#') continue;
                    if (grid[xx][yy] - 'A' >= 0 && grid[xx][yy] - 'A' < key_number) {
                        int lock = grid[xx][yy] - 'A';
                        if (((cur_state >> lock) & 1) == 0) continue;
                        if (visited[xx][yy][cur_state] != -1) continue;
                        visited[xx][yy][cur_state] = visited[pos.first][pos.second][cur_state] + 1;
                        q.push(MK(MK(xx, yy), cur_state));
                    } else if (grid[xx][yy] - 'a' >= 0 && grid[xx][yy] - 'a' < key_number) {
                        int lock = grid[xx][yy] - 'a';
                        int next_state = (cur_state | (1 << lock));
                        if (visited[xx][yy][next_state] != -1) continue;
                        visited[xx][yy][next_state] = visited[pos.first][pos.second][cur_state] + 1;
                        q.push(MK(MK(xx, yy), next_state));
                    } else {
                        if (visited[xx][yy][cur_state] != -1) continue;
                        visited[xx][yy][cur_state] = visited[pos.first][pos.second][cur_state] + 1;
                        q.push(MK(MK(xx, yy), cur_state));
                    }
                }
            }
        }
        return -1;
    }
    bool check_boundary(int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
};