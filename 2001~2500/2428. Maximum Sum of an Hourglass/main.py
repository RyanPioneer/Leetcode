"""
Source: https://rb.gy/dc8zp
Date: 2023/8/14
Skill:
Ref:
Runtime: 268 ms, faster than 65.63%
Memory Usage: 19.48 MB, less than 42.50%
Time complexity:
Space complexity:
Constraints:
    3 <= m, n <= 150
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[0 for _ in range(n - 3 + 1)] for _ in range(m - 3 + 1)]
        num, res = 0, 0
        for i in range(3):
            for j in range(3):
                num += grid[i][j]
        dp[0][0] = num
        for i in range(3, m):
            for j in range(3):
                num += grid[i][j] - grid[i - 3][j]
            dp[i - 2][0] = num
        for i in range(1, n - 2):
            num = dp[0][i - 1]
            for j in range(3):
                num += grid[j][i + 2] - grid[j][i - 1]
            dp[0][i] = num
            for j in range(3, m):
                for k in range(3):
                    num += grid[j][i + k] - grid[j - 3][i + k]
                dp[j - 2][i] = num
        for i in range(m - 2):
            for j in range(n - 2):
                res = max(res, dp[i][j] - grid[i + 1][j] - grid[i + 1][j + 2])
        return res


if __name__ == "__main__":
    s = Solution()

