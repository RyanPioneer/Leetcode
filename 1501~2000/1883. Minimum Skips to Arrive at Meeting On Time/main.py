"""
Source: https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/
Date: 2023/3/26
Skill: Dynamic Programming
Runtime: 2992 ms, faster than 76.39%
Memory Usage: 28 MB, less than 94.85%
Time complexity:
Space complexity:
Constraints:
    1 <= dist.length <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minSkips(self, dist: List[int], speed: int, hoursBefore: int) -> int:
        n, dp = len(dist), [[1e10 for _ in range(len(dist))] for _ in range(len(dist))]
        dp[0][0], eps = 0, 1e-9  # * Because of precision issues
        for i in range(1, n):
            dp[i][0] = math.ceil(dp[i-1][0] + dist[i-1] / speed - eps)
            for j in range(1, i+1):
                dp[i][j] = min(math.ceil(dp[i-1][j] + dist[i-1] / speed - eps),
                               dp[i-1][j-1] + dist[i-1] / speed)

        for i in range(n):
            if dp[n-1][i] + dist[n-1] / speed <= hoursBefore:
                return i
        return -1


if __name__ == "__main__":
    s = Solution()
    dist = [7, 3, 5, 5]
    res = s.minSkips(dist, 2, 10)
