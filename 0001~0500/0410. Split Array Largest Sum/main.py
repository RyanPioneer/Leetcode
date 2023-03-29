"""
Source: https://leetcode.com/problems/split-array-largest-sum/
Date: 2023/3/29
Skill: Dynamic programming
Runtime: TLE
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
    0 <= nums[i] <= 10^6
    1 <= k <= min(50, nums.length)
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        nums.insert(0, 0)
        dp, sz = [[math.inf for _ in range(k + 1)] for _ in range(len(nums))], len(nums)
        dp[0][0] = 0
        for i in range(1, sz):
            for j in range(1, min(i, k) + 1):
                cur_sum = 0
                for l in range(i, j - 1, -1):
                    cur_sum += nums[l]
                    dp[i][j] = min(dp[i][j], max(cur_sum, dp[l - 1][j - 1]))

        return dp[sz-1][k]


if __name__ == "__main__":
    s = Solution()
