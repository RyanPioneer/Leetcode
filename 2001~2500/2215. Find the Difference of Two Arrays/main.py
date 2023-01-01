"""
Source: https://leetcode.com/problems/find-the-difference-of-two-arrays/
Date: 2022/12/20
Skill: 
Runtime: 203 ms, faster than 86.40% 
Memory Usage: 14.4 MB, less than 15.25%
Time complexity: 
Space complexity: 
Constraints: 
   
"""

from typing import List
from collections import defaultdict


class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        dict, res = defaultdict(int), [[] for i in range(2)]
        for num in nums1:
            dict[num] = 1
        for num in nums2:
            if dict[num] >= 1:
                dict[num] += 1
            else:
                res[1].append(num)
                dict[num] = 2
        
        for value, cnt in dict.items():
            if cnt == 1:
                res[0].append(value)
                
        return res