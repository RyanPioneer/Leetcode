"""
Source: https://leetcode.com/problems/maximum-subarray/description/
Date: 2023/1/18
Skill: Dynamic Programming - Memoization
Ref:
Runtime: 1470 ms, faster than 35.25%
Memory Usage: 144.1 MB, less than 5.81%
Time complexity:
Space complexity:
Constraints:
    -10^4 <= nums[i] <= 10^4
"""

from typing import List, Optional
import math

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sz = len(nums)
        dp = [[-1, -1] for _ in range(sz)]

        def helper(index, before_chosen):
            if index == sz: return 0 if before_chosen else -math.inf
            if dp[index][before_chosen] != -1: return dp[index][before_chosen]
            if before_chosen:
                dp[index][before_chosen] = max(0, nums[index] + helper(index + 1, True))
                return dp[index][before_chosen]
            else:
                dp[index][before_chosen] = max(nums[index] + helper(index + 1, True), helper(index + 1, False))
                return dp[index][before_chosen]

        return helper(0, False)