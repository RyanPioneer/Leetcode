"""
Source: https://leetcode.com/problems/stone-game-iii/
Date: 2023/4/5
Skill:
Ref:
Runtime: 2108 ms, faster than 97.55%
Memory Usage: 18.5 MB, less than 78.92%
Time complexity:
Space complexity:
Constraints:
    1 <= stoneValue.length <= 5 * 10^4
    -1000 <= stoneValue[i] <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        dp, sz = [0 for _ in range(len(stoneValue))], len(stoneValue)
        dp[sz - 1] = stoneValue[sz - 1]
        if sz > 1:
            dp[sz - 2] = max(stoneValue[sz - 2] + stoneValue[sz - 1], stoneValue[sz - 2] - dp[sz - 1])
        if sz > 2:
            dp[sz - 3] = max(stoneValue[sz - 3] + stoneValue[sz - 2] + stoneValue[sz - 1],
                             stoneValue[sz - 3] + stoneValue[sz - 2] - dp[sz - 1], stoneValue[sz - 3] - dp[sz - 2])
        for i in range(sz - 4, -1, -1):
            dp[i] = max(stoneValue[i] - dp[i + 1], stoneValue[i] + stoneValue[i + 1] -
                        dp[i + 2], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3])
        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        else:
            return "Tie"


if __name__ == "__main__":
    s = Solution()
