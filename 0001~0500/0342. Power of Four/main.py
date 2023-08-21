"""
Source: https://rb.gy/3wep8
Date: 2023/8/21
Skill:
Ref:
Runtime: 42 ms, faster than 69.21%
Memory Usage: 16.32 MB, less than 26.51%
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
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False
        num = 1
        while num < n:
            num <<= 2
        return num == n


if __name__ == "__main__":
    s = Solution()
