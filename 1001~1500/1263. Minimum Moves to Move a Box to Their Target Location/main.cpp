/**
 * Source: ibit.ly/2eoCE
 * Date: 2023/10/5
 * Skill:
 * Runtime: 14 ms, faster than 98.31% of C++ online submissions
 * Memory Usage: 12.19 MB, less than 88.14% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 20
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
    struct Node {
        int bx, by, px, py;
    };
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), tx, ty, dir[5] = {0, 1, 0, -1, 0};
        Node initial;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    initial.px = i;
                    initial.py = j;
                } else if (grid[i][j] == 'B') {
                    initial.bx = i;
                    initial.by = j;
                } else if (grid[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }
            }
        int memo[21][21][21][21];
        memset(memo, -1, sizeof(memo));
        memo[initial.bx][initial.by][initial.px][initial.py] = 0;
        deque<Node> q;
        q.push_back(initial);
        while (!q.empty()) {
            auto [bx, by, px, py] = q.front();
            q.pop_front();
            if (bx == tx && by == ty)
                return memo[bx][by][px][py];
            for (int i = 0; i < 4; i++) {
                int px2 = px + dir[i], py2 = py + dir[i + 1];
                if (px2 < 0 || px2 >= m || py2 < 0 || py2 >= n)
                    continue;
                if (memo[bx][by][px2][py2] != -1)
                    continue;
                if (grid[px2][py2] == '#')
                    continue;
                if (px2 == bx && py2 == by)
                    continue;
                memo[bx][by][px2][py2] = memo[bx][by][px][py];
                q.push_front({bx, by, px2, py2});
            }
            if ((abs(bx - px) + abs(by - py)) == 1) {
                for (int i = 0; i < 4; i++) {
                    int px2 = px + dir[i], py2 = py + dir[i + 1];
                    if (px2 == bx && py2 == by) {
                        int bx2 = bx + dir[i], by2 = by + dir[i + 1];
                        if (bx2 < 0 || bx2 >= m || by2 < 0 || by2 >= n)
                            continue;
                        if (memo[bx2][by2][px2][py2] != -1)
                            continue;
                        if (grid[bx2][by2] == '#')
                            continue;
                        memo[bx2][by2][px2][py2] = memo[bx][by][px][py] + 1;
                        q.push_back({bx2, by2, px2, py2});
                    }
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<char>> grid{{'#', '#', '#', '#', '#', '#'},
                              {'#', 'T', '#', '#', '#', '#'},
                              {'#', '.', '.', 'B', '.', '#'},
                              {'#', '.', '#', '#', '.', '#'},
                              {'#', '.', '.', '.', 'S', '#'},
                              {'#', '#', '#', '#', '#', '#'}};
    int res = s.minPushBox(grid);
    cout << res << endl;
}