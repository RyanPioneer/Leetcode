"""
Source: https://rb.gy/knayv
Date: 2023/8/21
Skill:
Ref:
Runtime: 5146 ms, faster than 35.90%
Memory Usage: 31.94 MB, less than 76.92%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 10 ** 4
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
    def distinctSequences(self, n: int) -> int:
        if n == 1:
            return 6
        mod, dp, res = 10 ** 9 + 7, [[[0 for _ in range(6)] for _ in range(6)] for _ in range(n)], 0
        for i in range(6):
            for j in range(6):
                if i == j:
                    continue
                if math.gcd(i + 1, j + 1) == 1:
                    dp[1][i][j] = 1
        for i in range(2, n):
            for j in range(6):
                for k in range(6):
                    if k == j:
                        continue
                    for l in range(6):
                        if l == j or l == k:
                            continue
                        if math.gcd(j + 1, l + 1) == 1:
                            dp[i][l][j] += dp[i - 1][k][l]
                            dp[i][l][j] %= mod

        for i in range(6):
            for j in range(6):
                res += dp[-1][i][j]
                res %= mod
        return res


if __name__ == "__main__":
    s = Solution()
