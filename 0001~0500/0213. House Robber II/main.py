"""
Source: https://leetcode.com/problems/house-robber-ii/
Date: 2022/12/14
Skill: Since House[1] and House[n] are adjacent, they cannot be robbed together. 
        Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], 
        depending on which choice offers more money.
Runtime: 27 ms, faster than 98.95% 
Memory Usage: 13.7 MB, less than 98.23%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 100
    0 <= nums[i] <= 1000
"""

from typing import List, Optional
import math

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1: return nums[0]
        def find_res(nums: List[int]):
            if len(nums) == 1: return nums[0]
            if len(nums) >= 3: nums[2] += nums[0]
            for i in range(3, len(nums)):
                nums[i] += max(nums[i-2], nums[i-3])
            return max(nums[len(nums)-1], nums[len(nums)-2])
        return max(find_res(nums[0:len(nums)-1]), find_res(nums[1:len(nums)]))
