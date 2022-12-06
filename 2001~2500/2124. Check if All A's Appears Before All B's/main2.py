"""
Source: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
Date: 2022/12/3
Skill: 
Runtime: 64 ms, faster than 22.33%
Memory Usage: 13.9 MB, less than 9.60% 
Time complexity: 
Space complexity: 
Constraints: 
    1 <= s.length <= 100
    s[i] is either 'a' or 'b'.
"""

from typing import List

class Solution:
    def checkString(self, s: str) -> bool:
        return "ba" not in s