"""
Source: https://leetcode.com/problems/minimum-sideway-jumps/
Date: 2023/4/12
Skill: Dynamic Programming
Ref:
Runtime: 3203 ms, faster than 82.74%
Memory Usage: 29.5 MB, less than 69.5%
Time complexity:
Space complexity:
Constraints:
    obstacles[0] == obstacles[n] == 0
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        dp, sz = [1, 0, 1], len(obstacles)
        for i in range(1, sz):
            if obstacles[i] == 0:
                dp[0], dp[1], dp[2] = min(min(dp[1], dp[2]) + 1, dp[0]), min(min(dp[0], dp[2]) + 1, dp[1]), \
                    min(min(dp[0], dp[1]) + 1, dp[2])
            elif obstacles[i] == 1:
                dp[0], dp[1], dp[2] = math.inf, min(dp[2] + 1, dp[1]), \
                    min(dp[1] + 1, dp[2])
            elif obstacles[i] == 2:
                dp[0], dp[1], dp[2] = min(dp[2] + 1, dp[0]), math.inf, \
                    min(dp[0] + 1, dp[2])
            else:
                dp[0], dp[1], dp[2] = min(dp[1] + 1, dp[0]), \
                    min(dp[0] + 1, dp[1]), math.inf

        return min(dp)


if __name__ == "__main__":
    s = Solution()
