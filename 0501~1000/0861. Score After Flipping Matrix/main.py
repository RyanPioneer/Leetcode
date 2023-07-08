"""
Source: https://rb.gy/ber7v
Date: 2023/7/8
Skill:
Ref:
Runtime: 43 ms, faster than 98.3%
Memory Usage: 16.5 MB, less than 12.32%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m, n, res = len(grid), len(grid[0]), 0

        def flip(i, is_row):
            if is_row:
                for j in range(n):
                    grid[i][j] = (grid[i][j] + 1) % 2
            else:
                for j in range(m):
                    grid[j][i] = (grid[j][i] + 1) % 2

        for i in range(m):
            if grid[i][0] == 0:
                flip(i, True)
        for i in range(1, n):
            one_num = 0
            for j in range(m):
                one_num += grid[j][i]
            if one_num * 2 < m:
                flip(i, False)

        for i in range(n - 1, -1, -1):
            num = 0
            for j in range(m):
                num += grid[j][i]
            res += num * (1 << (n - 1 - i))

        return res


if __name__ == "__main__":
    s = Solution()
    grid = [[0, 0, 1, 1], [1, 0, 1, 0], [1, 1, 0, 0]]
    res = s.matrixScore(grid)
