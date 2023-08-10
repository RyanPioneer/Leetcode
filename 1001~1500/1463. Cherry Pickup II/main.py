"""
Source: https://rb.gy/3480c
Date: 2023/8/10
Skill:
Ref:
Runtime: 1900 ms, faster than 45.55%
Memory Usage: 16.86 MB, less than 95.81%
Time complexity:
Space complexity:
Constraints:
    2 <= rows, cols <= 70
    0 <= grid[i][j] <= 100
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n, res = len(grid), len(grid[0]), 0
        dp = [[-1 for _ in range(n)] for _ in range(n)]
        dp[0][n - 1] = grid[0][0] + grid[0][-1]
        for i in range(1, m):
            dp2 = []
            for t in range(n):
                dp2.append(dp[t].copy())
            for j in range(n):
                for k in range(n):
                    if j == k:
                        num = grid[i][j]
                    else:
                        num = grid[i][j] + grid[i][k]
                    for l in range(j - 1, j + 2):
                        if l < 0 or l >= n:
                            continue
                        for m in range(k - 1, k + 2):
                            if m < 0 or m >= n or dp2[l][m] == -1:
                                continue
                            dp[k][j] = max(dp[k][j], dp2[l][m] + num)

        for i in range(n):
            res = max(res, max(dp[i]))
        return res


if __name__ == "__main__":
    s = Solution()
    grid = [[3, 1, 1], [2, 5, 1], [1, 5, 5], [2, 1, 1]]
    res = s.cherryPickup(grid)
    print(res)
