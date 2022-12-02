"""
Source: https://leetcode.com/problems/find-the-highest-altitude/
Date: 2022/12/2
Skill: 
Runtime: 74 ms, faster than 25.07%
Memory Usage: 13.8 MB, less than 96.38%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List
from itertools import accumulate

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        return max(0, max(accumulate(gain)))