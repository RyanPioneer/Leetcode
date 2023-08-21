"""
Source: https://rb.gy/a6yuv
Date: 2023/8/21
Skill:
Ref: https://rb.gy/43h8q
Runtime: 43 ms, faster than 88.82%
Memory Usage: 16.42 MB, less than 46.01%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10 ** 4
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
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s + s)[1: -1]


if __name__ == "__main__":
    s = Solution()

