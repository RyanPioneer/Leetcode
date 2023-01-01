"""
Source: https://leetcode.com/problems/next-greater-element-ii/description/
Date: 2022/12/18
Skill: 
Runtime: 644 ms, faster than 25.96% 
Memory Usage: 15.8 MB, less than 43.51%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
"""

from typing import List
from collections import defaultdict

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        nums, stack = nums+nums, []
        ans = [-1]*len(nums)
        for index in range(len(nums)):
            while stack and nums[stack[-1]] < nums[index]:
                ans[stack.pop()] = nums[index]
            stack.append(index)
        
        return ans[:len(nums)//2]