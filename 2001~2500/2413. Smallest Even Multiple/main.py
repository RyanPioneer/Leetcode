"""
Source: https://leetcode.com/problems/smallest-even-multiple/
Date: 2022/12/1
Skill: 
Runtime: 32 ms, faster than 91.52%
Memory Usage: 13.9 MB, less than 48.96%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        if n%2 == 0:
            return n
        else:
            return n*2