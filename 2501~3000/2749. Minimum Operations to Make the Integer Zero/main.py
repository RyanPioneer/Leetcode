"""
Source: https://rb.gy/iy941
Date: 2023/7/21
Skill:
Ref:
Runtime: 46 ms, faster than 78.13%
Memory Usage: 16.32 MB, less than 40.27%
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
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        k = 1
        while True:
            num1 -= num2
            if num1 < k:
                return -1
            bit_num = num1.bit_count()
            if bit_num <= k:
                return k
            k += 1


if __name__ == "__main__":
    s = Solution()
