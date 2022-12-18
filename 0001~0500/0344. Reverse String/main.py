"""
Source: https://leetcode.com/problems/reverse-string/
Date: 2022/12/8
Skill: 
Runtime: 201 ms, faster than 95.52% 
Memory Usage: 18.4 MB, less than 41.74%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= s.length <= 10^5
"""

from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(len(s)//2):
            s[i], s[len(s)-i-1] = s[len(s)-i-1], s[i]