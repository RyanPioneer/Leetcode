"""
Source: https://leetcode.com/problems/intersection-of-multiple-arrays/
Date: 2022/12/20
Skill: 
Runtime: 88 ms, faster than 78.26% 
Memory Usage: 14.4 MB, less than 26.93%
Time complexity: 
Space complexity: 
Constraints: 
   
"""

from typing import List
from collections import Counter


class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        s = set(nums[0])
        for i in range(1, len(nums)):
            s = s & set(nums[i])
        return sorted(s)