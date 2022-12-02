"""
Source: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
Date: 2022/12/2
Skill: 
Runtime: 170 ms, faster than 97.73%
Memory Usage: 15.5 MB, less than 20.91%
Time complexity: 
Space complexity: 
Constraints: 
    4 <= nums.length <= 10^4
    1 <= nums[i] <= 10^4
"""

from typing import List

class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums)-1]*nums[len(nums)-2]-nums[0]*nums[1]