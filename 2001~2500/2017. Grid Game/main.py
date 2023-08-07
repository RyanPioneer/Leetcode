"""
Source: https://rb.gy/lcnwy
Date: 2023/8/7
Skill:
Ref: https://rb.gy/3oosc
Runtime: WA
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 5 * 10 ** 4
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        dp, n = [[0 for _ in range(len(grid[0]))] for _ in range(2)], len(grid[0])
        dp[0][0], dp[1][0], point = grid[0][0], grid[0][0] + grid[1][0], 0
        for i in range(1, n):
            dp[0][i] = dp[0][i - 1] + grid[0][i]
            if dp[0][i] > dp[1][i - 1]:
                point = i
                dp[1][i] = dp[0][i] + grid[1][i]
            else:
                dp[1][i] = dp[1][i - 1] + grid[1][i]

        for i in range(point + 1):
            grid[0][i] = 0
        for i in range(point, n):
            grid[1][i] = 0

        dp[0][0], dp[1][0] = grid[0][0], grid[0][0] + grid[1][0]
        for i in range(1, n):
            dp[0][i] = dp[0][i - 1] + grid[0][i]
            if dp[0][i] > dp[1][i - 1]:
                dp[1][i] = dp[0][i] + grid[1][i]
            else:
                dp[1][i] = dp[1][i - 1] + grid[1][i]

        return dp[-1][-1]


if __name__ == "__main__":
    s = Solution()
    grid = [[2, 5, 4], [1, 5, 1]]
    res = s.gridGame(grid)
    print(res)
