"""
Source: https://rb.gy/ni6jf
Date: 2023/7/18
Skill:
Ref:
Runtime: 519 ms, faster than 61.27%
Memory Usage: 29.61 MB, less than 75.49%
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
    def maximumGroups(self, grades: List[int]) -> int:
        sz, lo, hi = len(grades), 1, len(grades)
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if mid * (mid + 1) // 2 > sz:
                hi = mid - 1
            else:
                lo = mid
        return lo


if __name__ == "__main__":
    s = Solution()
