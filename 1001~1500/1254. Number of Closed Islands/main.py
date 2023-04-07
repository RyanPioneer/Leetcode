"""
Source: https://leetcode.com/problems/number-of-closed-islands/
Date: 2023/4/6
Skill:
Ref:
Runtime: 129 ms, faster than 66.5%
Memory Usage: 14.4 MB, less than 80.22%
Time complexity:
Space complexity:
Constraints:
    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        row, col, res = len(grid), len(grid[0]), 0
        directions = [0, 1, 0, -1, 0]

        def check_feasible(x, y):
            return 0 <= x < row and 0 <= y < col

        def make_land_become_water(x, y):
            q = deque([(x, y)])
            while q:
                cur_x, cur_y = q.popleft()
                for i in range(4):
                    next_x, next_y = cur_x + directions[i], cur_y + directions[i + 1]
                    if check_feasible(next_x, next_y) and grid[next_x][next_y] == 0:
                        grid[next_x][next_y] = 1
                        q.append((next_x, next_y))

        for i in range(row):
            if grid[i][0] == 0:
                grid[i][0] = 1
                make_land_become_water(i, 0)
            if grid[i][col - 1] == 0:
                grid[i][col - 1] = 1
                make_land_become_water(i, col - 1)

        for i in range(col):
            if grid[0][i] == 0:
                grid[0][i] = 1
                make_land_become_water(0, i)
            if grid[row - 1][i] == 0:
                grid[row - 1][i] = 1
                make_land_become_water(row - 1, i)

        for i in range(1, row - 1):
            for j in range(1, col - 1):
                if grid[i][j] == 0:
                    res += 1
                    make_land_become_water(i, j)

        return res


if __name__ == "__main__":
    s = Solution()
