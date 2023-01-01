"""
Source: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
Date: 2022/12/25
Skill: 
Runtime: 45 ms, faster than 99.75% 
Memory Usage: 13.8 MB, less than 87.29%
Time complexity: 
Space complexity: 
Constraints: 
    2 <= nums.length <= 500
    0 <= nums[i] <= 100
"""

from typing import List
from collections import defaultdict

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        sorted_nums = list(nums)
        sorted_nums.sort()
        dict = defaultdict(int)
        for i in range(1, len(nums)):
            if sorted_nums[i] != sorted_nums[i-1]:
                dict[sorted_nums[i]] = i
                
        for i in range(0, len(nums)):
            sorted_nums[i] = dict[nums[i]]
        
        return sorted_nums