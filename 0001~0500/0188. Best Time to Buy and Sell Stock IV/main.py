"""
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
Date: 2023/2/12
Skill: Dynamic Programming
Runtime: 143 ms, faster than 79.46%
Memory Usage: 13.9 MB, less than 91.48%
Time complexity:
Space complexity:
Constraints:
    1 <= k <= 100
    1 <= prices.length <= 1000
    0 <= prices[i] <= 1000
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        hold, sold = [-math.inf for _ in range(k)], [0 for _ in range(k)]
        for price in prices:
            hold_old, sold_old = list(hold), list(sold)
            hold[0], sold[0] = max(hold_old[0], -price), max(sold_old[0], hold_old[0] + price)
            for j in range(1, k):
                hold[j], sold[j] = max(hold_old[j], sold_old[j-1]-price), max(sold_old[j], hold_old[j] + price)

        return max(sold)


if __name__ == "__main__":
    s = Solution