"""
Source: https://rb.gy/e0k2x
Date: 2023/8/21
Skill:
Ref:
Runtime: 2163 ms, faster than 67.31%
Memory Usage: 16.88 MB, less than 98.90%
Time complexity:
Space complexity:
Constraints:
    2 <= locations.length <= 100
    1 <= fuel <= 200
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right
from functools import cache


class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        mod, sz, res = 10 ** 9 + 7, len(locations), 0
        dp = [[0 for _ in range(fuel + 1)] for _ in range(sz)]
        dp[start][0] = 1
        for i in range(fuel + 1):
            for j in range(sz):
                if dp[j][i] == 0:
                    continue
                for k in range(sz):
                    if k == j:
                        continue
                    if i + abs(locations[j] - locations[k]) <= fuel:
                        dp[k][i + abs(locations[j] - locations[k])] += dp[j][i]
                        dp[k][i + abs(locations[j] - locations[k])] %= mod

        for i in range(fuel + 1):
            res += dp[finish][i]
            res %= mod
        return res


if __name__ == "__main__":
    s = Solution()
