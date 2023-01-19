"""
Source: https://leetcode.com/problems/maximum-subarray/description/
Date: 2023/1/18
Skill: Dynamic Programming - Tabulation
Ref:
Runtime: 825 ms, faster than 56.42%
Memory Usage: 28.6 MB, less than 33.14%
Time complexity:
Space complexity:
Constraints:
    -10^4 <= nums[i] <= 10^4
"""

from typing import List, Optional
import math

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [nums[0], nums[0]]
        for i in range(1, len(nums)):
            dp[0] = max(nums[i], dp[0]+nums[i])
            dp[1] = max(dp[1], dp[0])

        return dp[1]