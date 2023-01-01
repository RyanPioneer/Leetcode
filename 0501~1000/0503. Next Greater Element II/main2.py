"""
Source: https://leetcode.com/problems/next-greater-element-ii/description/
Date: 2022/12/18
Skill: 
Runtime: 212 ms, faster than 94.13% 
Memory Usage: 15.5 MB, less than 86.76%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
"""

from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ans, stack = [-1]*len(nums), []
        for index in range(len(nums)):
            while stack and nums[stack[-1]] < nums[index]:
                ans[stack.pop()] = nums[index]
            stack.append(index)
        for index in range(len(nums)):
            while stack and nums[stack[-1]] < nums[index]:
                ans[stack.pop()] = nums[index]
        
        return ans