"""
Source: https://leetcode.com/problems/stone-game-viii/
Date: 2023/4/5
Skill:
Ref:
Runtime: 1236 ms, faster than 37.50%
Memory Usage: 28 MB, less than 62.50%
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
    def stoneGameVIII(self, stones: List[int]) -> int:
        dp, sz = [0 for _ in range(len(stones) + 1)], len(stones)
        presum = [0]
        for i in range(sz):
            presum.append(presum[i] + stones[i])
        dp[2] = sum(stones)
        for i in range(3, sz + 1):
            dp[i] = max(dp[i - 1], presum[sz - i + 2] - dp[i - 1])
        return dp[sz]


if __name__ == "__main__":
    s = Solution()
