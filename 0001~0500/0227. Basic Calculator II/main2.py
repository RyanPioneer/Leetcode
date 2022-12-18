"""
Source: https://leetcode.com/problems/basic-calculator-ii/description/
Date: 2022/12/17
Skill: 
Runtime: 206 ms, faster than 52.54% 
Memory Usage: 16.7 MB, less than 31.9%
Time complexity: 
Space complexity: 
Constraints: 

"""

from typing import List

class Solution:
    def calculate(self, s: str) -> int:
        stack, num, op = [], 0, "+"
        
        for i in range(len(s)):
            if s[i].isdigit():
                num = num*10+int(s[i])
            
            if s[i] in "+-*/" or i == len(s)-1:
                if op == "+":
                    stack.append(num)
                elif op == "-":
                    stack.append(-num)
                elif op == "*":
                    stack[-1] *= num
                else:
                    stack[-1] = int(stack[-1]/num)
                
                op = s[i]
                num = 0
                
        return sum(stack)