"""
Source: https://leetcode.com/problems/koko-eating-bananas/
Date: 2023/3/9
Skill: Binary Search
Runtime: 484 ms, faster than 63.11%
Memory Usage: 15.5 MB, less than 62.86%
Time complexity:
Space complexity:
Constraints:
    1 <= piles[i] <= 10^9
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
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        lo, hi = 1, max(piles)
        while lo < hi:
            mid, cnt = (lo + hi) // 2, 0
            for pile in piles:
                cnt += math.ceil(pile / mid)
            if cnt > h:
                lo = mid + 1
            else:
                hi = mid

        return lo

if __name__ == "__main__":
    s = Solution()
