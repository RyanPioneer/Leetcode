"""
Source: https://rb.gy/05f2x
Date: 2023/8/20
Skill:
Runtime: 1527 ms, faster than 100.00%
Memory Usage: 71.34 MB, less than 20.00%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
from functools import cache


class Solution:
    def maximizeTheProfit(self, n: int, offers: List[List[int]]) -> int:
        dp, prev = [0 for _ in range(n + 1)], defaultdict(list)
        for offer in offers:
            prev[offer[1]].append([offer[0], offer[2]])
        for i in range(n):
            dp[i + 1] = dp[i]
            for pre, price in prev[i]:
                dp[i + 1] = max(dp[i + 1], dp[pre] + price)
        return dp[-1]


if __name__ == "__main__":
    s = Solution()
    n, offers = 9, [[2, 3, 4], [7, 7, 8], [2, 5, 3]]
    res = s.maximizeTheProfit(n, offers)
    print(res)
