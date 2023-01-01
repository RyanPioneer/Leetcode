"""
Source: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
Date: 2022/12/31
Skill: BFS
Runtime: 725 ms, faster than 77.42%
Memory Usage: 14.2 MB, less than 94.65%
Time complexity:
Space complexity:
Constraints:
    1 <= grid.length, grid[i].length <= 100
    grid[i][j] is 0 or 1
"""

from typing import List, Optional
from collections import deque

class Solution:
    dir = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)]
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
            if grid[len(grid) - 1][len(grid) - 1] or grid[0][0]: return -1
            grid[0][0] = 1
            q = deque()
            q.append((0, 0, 1))

            def check_available(x, y):
                return x >= 0 and x < len(grid) and y >= 0 and y < len(grid)

            while q:
                cur_x, cur_y, dist = q.popleft()
                if cur_x == len(grid)-1 and cur_y == len(grid)-1:
                    return dist
                for dx, dy in Solution.dir:
                    if check_available(cur_x+dx, cur_y+dy) and grid[cur_x+dx][cur_y+dy] == 0:
                        q.append((cur_x+dx, cur_y+dy, dist+1))
                        grid[cur_x+dx][cur_y+dy] = 1

            return -1