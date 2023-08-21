"""
Source: https://rb.gy/e0k2x
Date: 2023/8/21
Skill:
Ref:
Runtime: 1334 ms, faster than 96.36%
Memory Usage: 22.18 MB, less than 57.02%
Time complexity:
Space complexity:
Constraints:
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
        mod, sz = 10 ** 9 + 7, len(locations)

        @cache
        def dfs(cur_pos, rem):
            nonlocal sz
            if rem <= 0:
                return cur_pos == finish
            if cur_pos == finish:
                num = 1
            else:
                num = 0
            for i in range(sz):
                if i == cur_pos:
                    continue
                if abs(locations[i] - locations[cur_pos]) + abs(locations[finish] - locations[i]) <= rem:
                    num += dfs(i, rem - abs(locations[i] - locations[cur_pos])) % mod
            return num % mod

        return dfs(start, fuel)


if __name__ == "__main__":
    s = Solution()
