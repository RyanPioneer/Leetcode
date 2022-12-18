"""
Source: https://leetcode.com/problems/climbing-stairs/description/
Date: 2022/12/12
Skill: 
Runtime: 54 ms, faster than 51.57% 
Memory Usage: 13.7 MB, less than 96.52%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= n <= 45
"""

from typing import List, Optional
import collections

class Solution:
    def climbStairs(self, n: int) -> int:
        prev, cur = 1, 1
        for i in range(2, n+1):
            prev, cur = cur, prev+cur
        return cur
        