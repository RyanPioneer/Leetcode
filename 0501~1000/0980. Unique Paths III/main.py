"""
Source: https://leetcode.com/problems/unique-paths-iii/
Date: 2022/12/31
Skill: DFS
Runtime: 55 ms, faster than 92.11%
Memory Usage: 14 MB, less than 19.89%
Time complexity:
Space complexity:
Constraints:
    1 <= grid.length, grid[i].length <= 20
"""

from typing import List, Optional

# Definition for a binary tree node.
class Solution:
    dir = [(0,1), (0,-1), (1,0), (-1, 0)]
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        start_x, start_y, end_x, end_y, num = 0, 0, 0, 0, 1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    start_x, start_y = i, j
                elif grid[i][j] == 2:
                    end_x, end_y = i, j
                elif grid[i][j] == 0:
                    num += 1

        def check_feasible(x, y):
            return x >= 0 and x <  len(grid) and y >= 0 and y < len(grid[0]) and (grid[x][y] == 0 or grid[x][y] == 2)

        def dfs(cur_x, cur_y, dist):
            if cur_x == end_x and cur_y == end_y:
                return dist == num
            grid[cur_x][cur_y] = -1
            way = 0
            for x, y in Solution.dir:
                if check_feasible(cur_x+x, cur_y+y):
                    way += dfs(cur_x+x, cur_y+y, dist+1)

            grid[cur_x][cur_y] = 0
            return way

        return dfs(start_x, start_y, 0)

if __name__ == "__main__":
    s = Solution
    print(s.uniquePathsIII(s, [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]))