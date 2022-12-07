"""
Source: https://leetcode.com/problems/sort-the-people/
Date: 2022/12/7
Skill: 
Runtime: 305 ms, faster than 35.53% 
Memory Usage: 14.5 MB, less than 47.1%
Time complexity: 
Space complexity: 
Constraints: 
    All the values of heights are distinct.
"""

from typing import List

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [name for _,name in sorted(zip(heights,names))[::-1]]