"""
Source: https://rb.gy/n86qa
Date: 2023/8/4
Skill:
Ref:
Runtime: 1414 ms, faster than 92.35%
Memory Usage: 51.81 MB, less than 58.20%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        diff = [[0 for _ in range(n)] for _ in range(m)]
        one_row, one_col = [0 for _ in range(m)], [0 for _ in range(n)]
        for i in range(m):
            cnt = 0
            for j in range(n):
                cnt += grid[i][j]
            one_row[i] = cnt
        for i in range(n):
            cnt = 0
            for j in range(m):
                cnt += grid[j][i]
            one_col[i] = cnt

        for i in range(m):
            for j in range(n):
                diff[i][j] = 2 * one_row[i] - n + 2 * one_col[j] - m

        return diff


if __name__ == "__main__":
    s = Solution()
