"""
Source: https://leetcode.com/problems/reverse-words-in-a-string-iii/
Date: 2022/12/1
Skill: 
Runtime: 124 ms, faster than 24.01% 
Memory Usage: 14.9 MB, less than 13.96%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def reverseWords(self, s: str) -> str:
        stack, vec = [], []
        for w in reversed(s):
            if w == ' ':
                stack.append(vec)
                vec = []
            else:
                vec.append(w)
        stack.append(vec)
        vec = []
        while stack:
            vec.append(''.join(stack.pop()))
        return " ".join(vec)   