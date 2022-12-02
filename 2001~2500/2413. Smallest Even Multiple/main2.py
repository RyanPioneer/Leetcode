"""
Source: https://leetcode.com/problems/smallest-even-multiple/
Date: 2022/12/1
Skill: 
Runtime: 57 ms, faster than 41.12%
Memory Usage: 13.8 MB, less than 48.96%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        return n << (n & 1)