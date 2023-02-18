"""
Source: https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/
Date: 2023/2/17
Skill:
Runtime: 1011 ms, faster than 53.55%
Memory Usage: 17.3 MB, less than 71.63%
Time complexity:
Space complexity:
Constraints:
    grid[0][0] == grid[m - 1][n - 1] == 1
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def isPossibleToCutPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        for i in range(1, m):
            if grid[m-i][n-1] == 0:
                grid[m-i-1][n-1] = 0
        for i in range(1, n):
            if grid[m-1][n-i] == 0:
                grid[m-1][n-i-1] = 0

        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                if grid[i+1][j] == 0 and grid[i][j+1] == 0:
                    grid[i][j] = 0

        x1, y1, x2, y2 = 0, 0, 0, 0
        for i in range(m+n-3):
            if x1+1 < m and grid[x1+1][y1] == 1:
                x1 += 1
            elif y1+1 < n and grid[x1][y1+1] == 1:
                y1 += 1
            else:
                return True

            if y2+1 < n and grid[x2][y2+1] == 1:
                y2 += 1
            elif x2+1 < m and grid[x2+1][y2] == 1:
                x2 += 1
            else:
                return True

            if x1 == x2 and y1 == y2:
                return True

        return False


if __name__ == "__main__":
    s = Solution