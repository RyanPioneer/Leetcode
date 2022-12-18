"""
Source: https://leetcode.com/problems/basic-calculator/
Date: 2022/12/17
Skill: 
Runtime: 126 ms, faster than 74.67% 
Memory Usage: 15.5 MB, less than 33.58%
Time complexity: 
Space complexity: 
Constraints: 
    s consists of digits, '+', '-', '(', ')', and ' '.
"""

from typing import List

class Solution:
    def calculate(self, s: str) -> int:
        stack, nums, sign, sum, i = [], "0123456789", 1, 0, -1
        while i+1 < len(s):
            i += 1
            if s[i] == " ":
                continue
            elif s[i] in nums:
                num = s[i]
                while i+1 < len(s) and s[i+1] in nums:
                    i += 1
                    num += s[i]
                sum += sign*int(num)
                sign = 1
            elif s[i] == "(":
                stack.append((sum, sign))
                sum = 0
                sign = 1
            elif s[i] == ")":
                sum = stack[-1][0] + stack[-1][1]*sum
                stack.pop()
            elif s[i] == "-":
                sign *= -1
                
        return sum