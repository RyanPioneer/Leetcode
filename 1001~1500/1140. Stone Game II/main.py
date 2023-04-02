"""
Source: https://leetcode.com/problems/stone-game-ii/
Date: 2023/4/2
Skill:
Runtime: 262 ms, faster than 68.84%
Memory Usage: 15.7 MB, less than 54.35%
Time complexity:
Space complexity:
Constraints:
    1 <= piles.length <= 100
    1 <= piles[i] <= 10^4
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        dp, sz = [[-1 for _ in range(len(piles) * 2 + 1)] for _ in range(len(piles))], len(piles)

        def solve(i, M):
            if dp[i][M] != -1:
                return dp[i][M]
            if sz - i <= 2 * M:
                dp[i][M] = sum(piles[i:])
                return dp[i][M]
            cur_sum = sum(piles[i:])
            for j in range(1, 2 * M + 1):
                dp[i][M] = max(dp[i][M], cur_sum - solve(i + j, max(M, j)))
            return dp[i][M]

        return solve(0, 1)


if __name__ == "__main__":
    s = Solution()
    piles = [2, 7, 9, 4, 4]
    res = s.stoneGameII(piles)
    print(res)
