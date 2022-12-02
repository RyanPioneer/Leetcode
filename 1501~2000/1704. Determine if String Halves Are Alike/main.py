"""
Source: https://leetcode.com/problems/determine-if-string-halves-are-alike/
Date: 2022/12/1
Skill: 
Runtime: 67 ms, faster than 50.84%
Memory Usage: 14 MB, less than 33.58%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        length = len(s)
        num = 0
        
        def check_letter(c: chr) -> bool:
            if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'\
                or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U':
                    return True
            return False
        
        for x in range(length//2):
            if check_letter(s[x]):
                num += 1
        
        for x in range(length//2, length):
            if check_letter(s[x]):
                num -= 1
                
        if num == 0:
            return True
        else:
            return False