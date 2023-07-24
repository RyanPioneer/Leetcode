"""
Source: https://rb.gy/usx5f
Date: 2023/7/24
Skill:
Ref:
Runtime: 50 ms, faster than 41.09%
Memory Usage: 16.17 MB, less than 91.76%
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
    def isPerfectSquare(self, num: int) -> bool:
        lo, hi = 1, num
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if mid * mid == num:
                return True
            elif mid * mid > num:
                hi = mid - 1
            else:
                lo = mid

        return lo * lo == num


if __name__ == "__main__":
    s = Solution()
