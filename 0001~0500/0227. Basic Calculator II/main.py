"""
Source: https://leetcode.com/problems/basic-calculator-ii/description/
Date: 2022/12/17
Skill: 
Runtime: 322 ms, faster than 23.61% 
Memory Usage: 19.4 MB, less than 7.16%
Time complexity: 
Space complexity: 
Constraints: 

"""

from typing import List

class Solution:
    def calculate(self, s: str) -> int:
        operator_stack, operand_stack, i, sum = [], [], -1, 0
        while i+1 < len(s):
            i += 1
            if s[i] == " ": continue
            elif s[i] in "0123456789":
                num = s[i]
                while i+1 < len(s) and s[i+1] in "0123456789":
                    i += 1
                    num += s[i]
                if operator_stack and operator_stack[-1] in "*/":
                    op = operator_stack.pop()
                    if op == "*": operand_stack[-1] *= int(num)
                    else: operand_stack[-1] = int(operand_stack[-1]/int(num))
                else:
                    operand_stack.append(int(num))
            elif s[i] in "+-*/": operator_stack.append(s[i])
        
        while operand_stack:
            num = operand_stack.pop()
            if operator_stack:
                op = operator_stack.pop()
                if op == "+": sum += num
                else: sum -= num
            else: sum += num
            
        return sum