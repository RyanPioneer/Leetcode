"""
Source: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
Date: 2022/12/3
Skill: 
Runtime: 50 ms, faster than 63.68%
Memory Usage: 13.8 MB, less than 56.77%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= s.length <= 100
    s[i] is either 'a' or 'b'.
"""

from typing import List

class Solution:
    def checkString(self, s: str) -> bool:
        a = 0
        for c in s:
            if c == 'a':
                if a:
                    return False            
            else:
                a = 1
            
        return True
                