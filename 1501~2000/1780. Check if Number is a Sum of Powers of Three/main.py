"""
Source: https://rb.gy/sx2os
Date: 2023/8/21
Skill:
Ref:
Runtime: 40 ms, faster than 65.99%
Memory Usage: 16.04 MB, less than 99.49%
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
    def checkPowersOfThree(self, n: int) -> bool:
        num = 1
        while num < n:
            num *= 3
        while num >= 1 and n > 0:
            if n >= num:
                n -= num
            num //= 3
        return n == 0


if __name__ == "__main__":
    s = Solution()
