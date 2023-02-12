"""
Source: https://leetcode.com/problems/take-gifts-from-the-richest-pile/
Date: 2023/2/12
Skill:
Runtime: 53 ms, faster than 64.67%
Memory Usage: 13.9 MB, less than 77.23%
Time complexity:
Space complexity:
Constraints:
    1 <= gifts.length <= 10^3
    1 <= gifts[i] <= 10^9
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        gifts = [-gift for gift in gifts]
        heapify(gifts)
        for i in range(k):
            num = heappop(gifts)
            heappush(gifts, -math.isqrt(-num))

        return -sum(gifts)


if __name__ == "__main__":
    s = Solution
    gift, k = [25,64,9,4,100], 4
    res = s.pickGifts(s, gift, k)