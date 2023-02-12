"""
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
Date: 2023/2/12
Skill: Dynamic Programming
Runtime: 1168 ms, faster than 77.74%
Memory Usage: 28.9 MB, less than 35.79%
Time complexity:
Space complexity:
Constraints:
    1 <= prices.length <= 10^5
    0 <= prices[i] <= 10^5
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        hold1, release1, hold2, release2 = -prices[0], 0, -math.inf, 0
        for price in prices:
            hold1, release1, hold2, release2 = max(hold1, -price), max(release1, hold1 + price),\
                max(hold2, release1-price), max(release2, hold2 + price)

        return max(release1, release2)


if __name__ == "__main__":
    s = Solution