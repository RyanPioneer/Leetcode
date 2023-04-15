"""
Source: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
Date: 2023/4/15
Skill:
Ref:
Runtime: 5650 ms, faster than 27.68%
Memory Usage: 39.3 MB, less than 76.10%
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
from bisect import bisect_left, bisect_right


class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        dp, sz = [[0 for _ in range(k + 1)] for _ in range(len(piles))], len(piles)
        presum = [[0 for _ in range(len(piles[i]))] for i in range(sz)]
        for i in range(sz):
            presum[i][0] = piles[i][0]
            for j in range(1, len(piles[i])):
                presum[i][j] = presum[i][j - 1] + piles[i][j]

        for i in range(min(len(piles[0]), k)):
            dp[0][i + 1] = presum[0][i]

        for i in range(1, sz):
            length = len(piles[i])
            for j in range(1, k + 1):
                dp[i][j] = dp[i - 1][j]
                for l in range(min(length, j)):
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - l - 1] + presum[i][l])

        return dp[sz - 1][k]


if __name__ == "__main__":
    s = Solution()
