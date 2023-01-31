"""
Source: https://leetcode.com/problems/number-of-islands/
Date: 2023/1/31
Skill:
Runtime: 329 ms, faster than 63.71%
Memory Usage: 16.3 MB, less than 81.1%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 300
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        res, m, n = 0, len(grid), len(grid[0])
        dirs = [0, 1, 0, -1, 0]

        def check_valid(x, y):
            return x >= 0 and x < m and y >= 0 and y < n

        def dfs(x, y):
            grid[x][y] = "0"
            for i in range(4):
                if check_valid(x + dirs[i], y + dirs[i + 1]) and grid[x + dirs[i]][y + dirs[i + 1]] == "1":
                    dfs(x + dirs[i], y + dirs[i + 1])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    res += 1
                    dfs(i, j)

        return res