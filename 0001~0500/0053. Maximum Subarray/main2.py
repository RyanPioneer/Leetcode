"""
Source: https://leetcode.com/problems/maximum-subarray/description/
Date: 2023/1/18
Skill: Recursion
Ref:
Runtime: Time Limit Exceeded
Memory Usage:
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

        def helper(index, before_chosen):
            if index == sz: return 0 if before_chosen else -math.inf
            if before_chosen:
                return max(0, nums[index] + helper(index + 1, True))
            else:
                return max(nums[index] + helper(index + 1, True), helper(index + 1, False))

        return helper(0, False)