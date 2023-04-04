"""
Source: https://leetcode.com/problems/stone-game/
Date: 2023/4/4
Skill:
Ref: https://rb.gy/j5lw
Runtime: 70 ms, faster than 48.72%
Memory Usage: 15.9 MB, less than 46.23%
Time complexity:
Space complexity:
Constraints:
    2 <= piles.length <= 500
    piles.length is even.
    1 <= piles[i] <= 500
    sum(piles[i]) is odd.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        sz, total = len(piles), sum(piles)
        dp = [[0 for _ in range(sz)] for _ in range(sz)]

        def helper(start, end):
            if dp[start][end] != 0:
                return dp[start][end]
            if start == end:
                dp[start][end] = piles[start]
                return dp[start][end]
            dp[start][end] = sum(piles[start:end + 1]) - min(dp[start + 1][end], dp[start][end - 1])
            return dp[start][end]

        helper(0, sz - 1)
        return dp[0][sz - 1] * 2 > total


if __name__ == "__main__":
    s = Solution()
