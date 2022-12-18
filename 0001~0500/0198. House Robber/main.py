"""
Source: https://leetcode.com/problems/house-robber/description/
Date: 2022/12/14
Skill: Dynamic Programming
Runtime: 30 ms, faster than 96.26% 
Memory Usage: 13.8 MB, less than 97.62%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 100
"""

from typing import List, Optional
import math

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1: return nums[0]
        if len(nums) >= 3: nums[2] += nums[0]
        for i in range(3, len(nums)):
            nums[i] += max(nums[i-2], nums[i-3])
        return max(nums[len(nums)-1], nums[len(nums)-2])