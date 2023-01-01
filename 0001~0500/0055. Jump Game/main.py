"""
Source: https://leetcode.com/problems/jump-game/
Date: 2022/12/26
Skill: 
Runtime: 534 ms, faster than 80.35% 
Memory Usage: 15.2 MB, less than 82.53%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 10^4
    0 <= nums[i] <= 10^5
"""

from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        step = 0
        for index in range(0, len(nums)):
            if step < index:
                return False
            step = max(step, index+nums[index])
    
        return True