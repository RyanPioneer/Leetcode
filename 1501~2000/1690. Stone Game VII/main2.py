"""
Source: https://leetcode.com/problems/stone-game-vii/
Date: 2023/4/4
Skill:
Ref:
Runtime: 5127 ms, faster than 53.68%
Memory Usage: 38.3 MB, less than 35.29%
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
    def stoneGameVII(self, stones: List[int]) -> int:
        presum, sz, dp = [0], len(stones), \
            [[0 for _ in range(len(stones) + 1)] for _ in range(len(stones) + 1)]
        for i in range(sz):
            presum.append(presum[i] + stones[i])
        for i in range(sz - 1):
            dp[i + 1][i + 2] = max(stones[i], stones[i + 1])
        for length in range(3, sz + 1):
            for i in range(1, sz - length + 2):
                dp[i][i + length - 1] = max(presum[i + length - 1] - presum[i] - dp[i + 1][i + length - 1],
                                            presum[i + length - 2] - presum[i - 1] - dp[i][i + length - 2])
        return dp[1][sz]


if __name__ == "__main__":
    s = Solution()
    stones = [5, 3, 1, 4, 2]
    res = s.stoneGameVII(stones)
    print(res)
