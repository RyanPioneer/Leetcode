"""
Source: https://leetcode.com/problems/n-th-tribonacci-number/
Date: 2022/12/12
Skill: 
Runtime: 31 ms, faster than 92.86% 
Memory Usage: 13.8 MB, less than 59.86%
Time complexity: 
Space complexity: 
Constraints: 
    0 <= n <= 37
"""

from typing import List

class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        first, second, cur = 0, 1, 1
        for i in range(3, n+1):
            first, second, cur = second, cur, first+second+cur
        return cur