"""
Source: https://rb.gy/ulm40
Date: 2023/7/25
Skill:
Ref:
Runtime: 607 ms, faster than 33.75%
Memory Usage: 30.26 MB, less than 32.70%
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
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        lo, hi, sz = 0, len(arr) - 1, len(arr)
        while lo < hi:
            mid = (lo + hi) // 2
            if mid == 0:
                lo = mid + 1
            elif mid == sz - 1:
                hi = mid - 1
            elif arr[mid - 1] > arr[mid] > arr[mid + 1]:
                hi = mid - 1
            elif arr[mid - 1] < arr[mid] < arr[mid + 1]:
                lo = mid + 1
            else:
                return mid
        return lo


if __name__ == "__main__":
    s = Solution()
    arr = [18, 29, 38, 59, 98, 100, 99, 98, 90]
    res = s.peakIndexInMountainArray(arr)
