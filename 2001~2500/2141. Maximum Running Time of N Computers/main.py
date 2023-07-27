"""
Source: https://rb.gy/1l15f
Date: 2023/7/27
Skill:
Ref:
Runtime: 2494 ms, faster than 31.33%
Memory Usage: 30.81 MB, less than 22.89%
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
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        lo, hi = 0, sum(batteries)

        def check(minute):
            num = 0
            for battery in batteries:
                num += battery if battery < minute else minute
                if num >= n * minute:
                    return True
            return False

        while lo < hi:
            mid = (lo + hi + 1) // 2
            ans = check(mid)
            if ans:
                lo = mid
            else:
                hi = mid - 1

        return lo


if __name__ == "__main__":
    s = Solution()
