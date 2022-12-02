"""
Source: https://leetcode.com/problems/richest-customer-wealth/
Date: 2022/11/29
Skill: 
Runtime: 112 ms, faster than 52.86% 
Memory Usage: 14 MB, less than 32.98%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List, Optional

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(sum(i) for i in accounts)