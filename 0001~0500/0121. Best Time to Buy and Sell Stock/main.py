"""
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
Date: 2023/2/25
Skill:
Ref:
Runtime: 1003 ms, faster than 82.73%
Memory Usage: 25 MB, less than 32.77%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res, min_value = 0, math.inf
        for price in prices:
            if price < min_value:
                min_value = price
            res = max(res, price - min_value)

        return res


if __name__ == "__main__":
    s = Solution