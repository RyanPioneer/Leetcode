/**
 * Source: t.ly/HScAR
 * Date: 2025/1/29
 * Skill:
 * Ref:
 * Runtime: 19 ms, faster than 70.04% of C++ online submissions
 * Memory Usage: 32.46 MB, less than 53.14% of C++ online submissions
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
typedef tuple<int, int, int> TI3;


class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int Health) {
        priority_queue<TI3> pq;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> health(m, vector<int>(n, 0));
        health[0][0] = Health - grid[0][0];
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pq.push({Health - grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            if (x == m-1 && y == n-1) {
                return true;
            }
            for (const auto& dir : dirs) {
                int dx = dir[0], dy = dir[1];
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || h - grid[nx][ny] <= health[nx][ny]) {
                    continue;
                }
                health[nx][ny] = h - grid[nx][ny];
                pq.push({h - grid[nx][ny], nx, ny});
            }
        }

        return false;
    }
};
