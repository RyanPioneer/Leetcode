"""
Source: https://leetcode.com/problems/running-sum-of-1d-array/
Date: 2022/12/1
Skill: 
Runtime: 48 ms, faster than 83.63%
Memory Usage: 14 MB, less than 73.15%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 1000
    -10^6 <= nums[i] <= 10^6
"""

from typing import List

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        for i in range(1, len(nums)):
            nums[i] += nums[i-1]
        return nums