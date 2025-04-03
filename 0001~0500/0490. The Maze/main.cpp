/**
 * Source: t.ly/j-Ao_
 * Date: 2025/4/3
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 39.92 MB, less than 66.12% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= m, n <= 100
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
int dirs[5] = { 0, 1, 0, -1, 0 }, dp[MX][MX][4] = { 0 };

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
    {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({ start[0], start[1] });
        maze[start[0]][start[1]] = 1; // mark as visited

        auto check = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0;
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dirs[i], yy = y + dirs[i + 1];
                if (check(xx, yy)) {
                    if (xx == destination[0] && yy == destination[1]) {
                        return true;
                    }
                    q.push({ xx, yy });
                    maze[xx][yy] = 1; // mark as visited
                }
            }
        }
        return false;
    }
};
