"""
Source: https://rb.gy/hjjxb
Date: 2023/7/24
Skill:
Ref:
Runtime: 51 ms, faster than 72.58%
Memory Usage: 16.42 MB, less than 27.29%
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
    def mySqrt(self, x: int) -> int:
        lo, hi = 0, x
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if mid * mid == x:
                return mid
            elif mid * mid < x:
                lo = mid
            else:
                hi = mid - 1

        return lo


if __name__ == "__main__":
    s = Solution()
