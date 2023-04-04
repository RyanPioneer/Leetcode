"""
Source: https://leetcode.com/problems/stone-game-vii/
Date: 2023/4/4
Skill:
Ref:
Runtime: 5735 ms, faster than 24.26%
Memory Usage: 121.8 MB, less than 9.56%
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

        def solve(start, end):
            if dp[start][end] != 0:
                return dp[start][end]
            if start == end:
                dp[start][end] = 0
                return dp[start][end]
            if end == start + 1:
                dp[start][end] = max(stones[start - 1], stones[end - 1])
                return dp[start][end]
            dp[start][end] = max(presum[end] - presum[start] - solve(start + 1, end),
                                 presum[end - 1] - presum[start - 1] - solve(start, end - 1))
            return dp[start][end]

        return solve(1, sz)


if __name__ == "__main__":
    s = Solution()
    stones = [5, 3, 1, 4, 2]
    res = s.stoneGameVII(stones)
    print(res)
