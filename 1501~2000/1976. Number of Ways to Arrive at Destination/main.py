"""
Source: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
Date: 2022/12/6
Skill: 
Runtime: 124 ms, faster than 24.01% 
Memory Usage: 14.9 MB, less than 13.96%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        MOD = 1000000007
        