"""
Source: https://leetcode.com/problems/selling-pieces-of-wood/
Date: 2023/4/1
Skill:
Runtime: 7121 ms, faster than 28%
Memory Usage: 20.2 MB, less than 82%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 200
    1 <= prices.length <= 2 * 10^4
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for price in prices:
            dp[price[0]][price[1]] = price[2]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                for k in range(1, i):
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j])
                for k in range(1, j):
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k])

        return dp[m][n]


if __name__ == "__main__":
    s = Solution()
