"""
Source: https://rb.gy/knayv
Date: 2023/8/21
Skill:
Ref:
Runtime: 4564 ms, faster than 56.41%
Memory Usage: 96.42 MB, less than 51.28%
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
        mod, res = 10 ** 9 + 7, 0
        if n == 1:
            return 6

        @cache
        def dfs(prev_num, length):
            if length == 0:
                return 1
            num = 0
            for i in range(1, 7):
                if i not in prev_num and math.gcd(i, prev_num[-1]) == 1:
                    num += dfs((prev_num[-1], i), length - 1) % mod
            return num % mod

        for i in range(1, 7):
            for j in range(1, 7):
                if i == j:
                    continue
                if math.gcd(i, j) == 1:
                    res += dfs((i, j), n - 2) % mod
                    res %= mod
        return res


if __name__ == "__main__":
    s = Solution()
