/** 
 * Source: https://leetcode.com/problems/max-area-of-island/
 * Date: 2022/7/15
 * Skill: BFS
 * Runtime: 26 ms, faster than 68.48% of C++
 * Memory Usage: 27.1 MB, less than 11.23% of C++
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= m, n <= 50
 */

#include <iostream>
#include <vector>
#include <utility>
#include <queue>   
//#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    int area = explore(grid,i,j);
                    ans = (ans > area)?ans:area;
                }
            }
        }
        return ans;
    }

    int explore(vector<vector<int>>& grid, int x, int y) {
        vector<pair<int,int>> dir{make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)};
        queue<pair<int,int>>q;
        q.push(make_pair(x,y));
        grid[x][y] = 0;
        int area = 1;
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            for (int i = 0; i < 4; i++) {
                if (x + dir[i].first >= 0 && x + dir[i].first < grid.size() && 
                y + dir[i].second >= 0 && y + dir[i].second < grid[0].size() && 
                grid[x + dir[i].first][y + dir[i].second]) {
                    q.push(make_pair(x + dir[i].first,y + dir[i].second));
                    grid[x + dir[i].first][y + dir[i].second] = 0;
                    area++;
                }
            }
            q.pop();
        }
        return area;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();