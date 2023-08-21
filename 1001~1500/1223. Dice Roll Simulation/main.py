"""
Source: https://rb.gy/n86tt
Date: 2023/8/21
Skill:
Ref:
Runtime: 1587 ms, faster than 39.29%
Memory Usage: 193.56 MB, less than 20.24%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 5000
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
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        mod = 10 ** 9 + 7

        @cache
        def dfs(prev_num, consecutive_time, rem):
            if rem == 0:
                return 1
            num = 0
            for i in range(6):
                if i != prev_num:
                    num += dfs(i, 1, rem - 1) % mod
                elif consecutive_time < rollMax[prev_num]:
                    num += dfs(i, consecutive_time + 1, rem - 1) % mod
                num %= mod
            return num % mod

        return dfs(-1, 0, n)


if __name__ == "__main__":
    s = Solution()
