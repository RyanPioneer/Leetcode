"""
Source: https://rb.gy/fd0mi
Date: 2023/7/17
Skill:
Ref:
Runtime: 44 ms, faster than 75.54%
Memory Usage: 16.38 MB, less than 53.65%
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


class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        from math import lcm
        left, right = 1, 2 * 10 ** 9
        ab, bc, ac, abc = lcm(a, b), lcm(b, c), lcm(a, c), lcm(lcm(a, b), c)

        def count(num):
            return num // a + num // b + num // c - num // ab - num // ac - \
                num // bc + num // abc

        while left < right:
            mid = (left + right) // 2
            if count(mid) < n:
                left = mid + 1
            else:
                right = mid

        return left


if __name__ == "__main__":
    s = Solution()

