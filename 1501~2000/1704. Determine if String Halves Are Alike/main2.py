"""
Source: https://leetcode.com/problems/determine-if-string-halves-are-alike/
Date: 2022/12/1
Skill: Use Set to check equality
Runtime: 64 ms, faster than 57.01%
Memory Usage: 14 MB, less than 33.58%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = set("aeiouAEIOU")
        a = b = 0
        i, j = 0, len(s)-1
        while i < j:
            a += s[i] in vowels
            b += s[j] in vowels
            i += 1
            j -= 1
        return a == b