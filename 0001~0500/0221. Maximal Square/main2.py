"""
Source: https://leetcode.com/problems/maximal-square/
Date: 2023/2/1
Skill: Dynamic Programming
Runtime: 594 ms, faster than 99.19%
Memory Usage: 16.7 MB, less than 95.80%
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
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n, res = len(matrix), len(matrix[0]), 0
        dp = [0 for _ in range(n)]
        for i in range(n):
            if matrix[0][i] == "1":
                dp[i], res = 1, 1

        for i in range(1, m):
            prev = dp[0]
            if matrix[i][0] == "1":
                dp[0], res = 1, max(res, 1)
            else:
                dp[0] = 0
            for j in range(1, n):
                if matrix[i][j] == "1":
                    dp[j], prev = 1 + min(dp[j-1], dp[j], prev), dp[j]
                    res = max(res, dp[j])
                else:
                    dp[j], prev = 0, dp[j]

        return pow(res, 2)