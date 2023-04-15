"""
Source: https://leetcode.com/problems/maximum-number-of-points-with-cost/
Date: 2023/4/15
Skill:
Ref:
Runtime: 2431 ms, faster than 21.49%
Memory Usage: 47.7 MB, less than 70.9%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        row, col = len(points), len(points[0])
        dp = [[0 for _ in range(col)] for _ in range(row)]
        for i in range(col):
            dp[0][i] = points[0][i]

        for i in range(1, row):
            rolling_max = -math.inf
            for j in range(col):
                rolling_max = max(rolling_max, dp[i - 1][j] + j)
                dp[i][j] = points[i][j] - j + rolling_max

            rolling_max = -math.inf
            for j in range(col - 1, -1, -1):
                rolling_max = max(rolling_max, dp[i - 1][j] - j)
                dp[i][j] = max(dp[i][j], points[i][j] + j + rolling_max)

        return max(dp[row - 1])


if __name__ == "__main__":
    s = Solution()
    points = [[1, 2, 3], [1, 5, 1], [3, 1, 1]]
    res = s.maxPoints(points)
