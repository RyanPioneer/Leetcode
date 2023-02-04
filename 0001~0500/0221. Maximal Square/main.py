"""
Source: https://leetcode.com/problems/maximal-square/
Date: 2023/2/1
Skill: Dynamic Programming
Runtime: 633 ms, faster than 94.51%
Memory Usage: 17 MB, less than 34.87%
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
        dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            if matrix[i][0] == "1":
                dp[i][0] = 1
        for i in range(n):
            if matrix[0][i] == "1":
                dp[0][i] = 1

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == "1":
                    dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])

        return pow(max(max(nums) for nums in dp), 2)