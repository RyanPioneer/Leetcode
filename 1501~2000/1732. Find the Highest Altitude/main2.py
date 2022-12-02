"""
Source: https://leetcode.com/problems/find-the-highest-altitude/
Date: 2022/12/2
Skill: 
Runtime: 33 ms, faster than 96.73%
Memory Usage: 13.9 MB, less than 55.47%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        res, cur = 0, 0
        for i in gain:
            cur += i
            if cur > res:
                res = cur
        return res