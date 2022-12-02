"""
Source: https://leetcode.com/problems/majority-element/
Date: 2022/11/30
Skill: Divide and Conquer
Runtime: 259 ms, faster than 71.89%
Memory Usage: 15.9 MB, less than 35.29%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        def majority_element_rec(lo,hi) -> int:
            if lo == hi:
                return nums[lo]
            mid = (lo+hi)//2
            left = majority_element_rec(lo,mid)
            right = majority_element_rec(mid+1,hi)
            if left == right:
                return left
            left_count = sum(1 for i in range(lo, mid+1) if nums[i] == left)
            right_count = sum(1 for i in range(mid+1, hi+1) if nums[i] == right)
            if left_count > right_count:
                return left
            else:
                return right
            
        return majority_element_rec(0,len(nums)-1)