"""
Source: https://rb.gy/bmapn
Date: 2023/8/15
Skill:
Ref: https://rb.gy/kw6ip
Runtime: 35 ms, faster than 94.51%
Memory Usage: 16.34 MB, less than 25.54%
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
    def isPowerOfTwo(self, n: int) -> bool:
        return n and not (n & (n - 1))


if __name__ == "__main__":
    s = Solution()

