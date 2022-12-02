/** 
 * Source: https://leetcode.com/problems/max-area-of-island/
 * Date: 2022/7/15
 * Skill: Recursive
 * Runtime: 20 ms, faster than 86.81% of C++
 * Memory Usage: 23.2 MB, less than 67.07% of C++
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
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (grid[i][j]) ans = max(ans, trav(i, j, grid));
        return ans;
    }
private:
    int n, m;
    int trav(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j]) return 0;
        grid[i][j] = 0;
        return 1 + trav(i-1, j, grid) + trav(i, j-1, grid) + trav(i+1, j, grid) + trav(i, j+1, grid);
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