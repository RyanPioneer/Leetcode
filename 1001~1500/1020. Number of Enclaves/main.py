"""
Source: https://leetcode.com/problems/number-of-enclaves/
Date: 2023/4/7
Skill:
Ref:
Runtime: 623 ms, faster than 89.99%
Memory Usage: 15.6 MB, less than 94.11%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 500
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
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
                    if check_feasible(next_x, next_y) and grid[next_x][next_y] == 1:
                        grid[next_x][next_y] = 0
                        q.append((next_x, next_y))

        for i in range(row):
            if grid[i][0] == 1:
                grid[i][0] = 0
                make_land_become_water(i, 0)
            if grid[i][col - 1] == 1:
                grid[i][col - 1] = 0
                make_land_become_water(i, col - 1)

        for i in range(col):
            if grid[0][i] == 1:
                grid[0][i] = 0
                make_land_become_water(0, i)
            if grid[row - 1][i] == 1:
                grid[row - 1][i] = 0
                make_land_become_water(row - 1, i)

        for i in range(1, row - 1):
            for j in range(1, col - 1):
                if grid[i][j] == 1:
                    res += 1

        return res


if __name__ == "__main__":
    s = Solution()
