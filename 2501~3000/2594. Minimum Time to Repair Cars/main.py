"""
Source: https://leetcode.com/problems/minimum-time-to-repair-cars/
Date: 2023/3/24
Skill: Binary search
Runtime: 2051 ms, faster than 32.89%
Memory Usage: 17.8 MB, less than 39.62%
Time complexity:
Space complexity:
Constraints:
    1 <= cars <= 10^6
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        low, high = 1, min(ranks) * cars ** 2

        while low < high:
            mid, num = (low + high) // 2, 0
            for rank in ranks:
                num += int(math.sqrt(mid / rank))
            if num < cars:
                low = mid + 1
            else:
                high = mid

        return low


if __name__ == "__main__":
    s = Solution()
    ranks = [4, 2, 3, 1]
    cars = 10
    res = s.repairCars(ranks, cars)
