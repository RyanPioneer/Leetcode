"""
Source: https://leetcode.com/problems/minimum-time-to-complete-trips/
Date: 2023/3/7
Skill: Binary Search
Runtime: 2778 ms, faster than 51.50%
Memory Usage: 28.8 MB, less than 20.50%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        lo, hi = min(time) * totalTrips // len(time), max(time) * totalTrips

        while lo < hi:
            mid = (lo + hi) // 2
            trip_num = 0
            for i in time:
                trip_num += mid // i

            if trip_num < totalTrips:
                lo = mid + 1
            else:
                hi = mid

        return lo


if __name__ == "__main__":
    s = Solution()
