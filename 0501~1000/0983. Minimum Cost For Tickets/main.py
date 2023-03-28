"""
Source: https://leetcode.com/problems/minimum-cost-for-tickets/
Date: 2023/3/28
Skill:
Runtime: 47 ms, faster than 64.11%
Memory Usage: 13.9 MB, less than 83.75%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp, myset, last_day = [0 for _ in range(max(days) + 1)], set(days), max(days)
        for i in range(1, last_day + 1):
            if i not in myset:
                dp[i] = dp[i - 1]
            else:
                day = dp[max(i-1, 0)] + costs[0]
                week = dp[max(i-7, 0)] + costs[1]
                month = dp[max(i-30, 0)] + costs[2]
                dp[i] = min(day, week, month)

        return dp[last_day]


if __name__ == "__main__":
    s = Solution()
