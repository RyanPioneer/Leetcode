"""
Source: https://rb.gy/wqjp2
Date: 2023/8/21
Skill:
Ref:
Runtime: 77 ms, faster than 80.02%
Memory Usage: 16.22 MB, less than 74.09%
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
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 3 ** 19 % n == 0


if __name__ == "__main__":
    s = Solution()

