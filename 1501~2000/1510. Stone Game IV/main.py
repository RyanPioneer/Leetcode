"""
Source: https://leetcode.com/problems/stone-game-iv/
Date: 2023/4/5
Skill:
Ref:
Runtime: 895 ms, faster than 47.78%
Memory Usage: 14.6 MB, less than 99.72%
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
    def winnerSquareGame(self, n: int) -> bool:
        dp = [0 for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, math.isqrt(i) + 1):
                if dp[i - j * j] == 0:
                    dp[i] = 1
                    break
        return dp[n]


if __name__ == "__main__":
    s = Solution()
