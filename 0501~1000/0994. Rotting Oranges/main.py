"""
Source: https://leetcode.com/problems/rotting-oranges/
Date: 2023/1/22
Skill:
Runtime: 74 ms, faster than 40.14%
Memory Usage: 13.9 MB, less than 88.97%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 10
"""

from typing import List
from functools import lru_cache, cache

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n, res = len(grid), len(grid[0]), 0
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        fresh_orange, rotten_orange, next_rotten_orange = set(), set(), set()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    fresh_orange.add((i, j))
                elif grid[i][j] == 2:
                    rotten_orange.add((i, j))

        def check_valid(x, y):
            return x>=0 and x<m and y>=0 and y<n

        while rotten_orange and fresh_orange:
            for x, y in rotten_orange:
                for dir in dirs:
                    if check_valid(x+dir[0], y + dir[1]):
                        if (x+dir[0], y + dir[1]) in fresh_orange:
                            fresh_orange.remove((x+dir[0], y+dir[1]))
                            next_rotten_orange.add((x+dir[0], y+dir[1]))
            rotten_orange = set(next_rotten_orange)
            next_rotten_orange.clear()
            res += 1

        if fresh_orange: return -1
        else: return res