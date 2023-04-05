"""
Source: https://leetcode.com/problems/stone-game-v/
Date: 2023/4/5
Skill:
Ref:
Runtime: TLE
Memory Usage:
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
    def stoneGameV(self, stoneValue: List[int]) -> int:
        dp = [[0 for _ in range(len(stoneValue))] for _ in range(len(stoneValue))]
        presum, sz = [0], len(stoneValue)
        for i in range(sz):
            presum.append(presum[i] + stoneValue[i])
        for i in range(sz - 1):
            dp[i][i + 1] = min(stoneValue[i], stoneValue[i + 1])
        for length in range(3, sz + 1):
            for i in range(sz - length + 1):
                for first_length in range(1, length):
                    first_sum, second_sum = presum[i + first_length] - presum[i], \
                                            presum[i + length] - presum[i + first_length]
                    if first_sum > second_sum:
                        dp[i][i + length - 1] = max(dp[i][i + length - 1],
                                                    second_sum + dp[i + first_length][i + length - 1])
                    elif first_sum < second_sum:
                        dp[i][i + length - 1] = max(dp[i][i + length - 1],
                                                    first_sum + dp[i][i + first_length - 1])
                    else:
                        dp[i][i + length - 1] = max(dp[i][i + length - 1], first_sum +
                                                    max(dp[i + first_length][i + length - 1], dp[i][i + first_length - 1]))

        return dp[0][sz - 1]


if __name__ == "__main__":
    s = Solution()
