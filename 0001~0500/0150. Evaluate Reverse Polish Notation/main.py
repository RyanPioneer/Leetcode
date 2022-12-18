"""
Source: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
Date: 2022/12/17
Skill: 
Runtime: 69 ms, faster than 92.91% 
Memory Usage: 14.3 MB, less than 96.51%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= tokens.length <= 10^4
    tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
"""

from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i not in "+-*/":
                stack.append(int(i))
            else:
                num = stack.pop()
                if i == "+": stack[-1] += num
                elif i == "-": stack[-1] -= num
                elif i == "*": stack[-1] *= num
                else: stack[-1] = int(stack[-1]/num)
                #! Note:  stack[-1] //= num: 向下取整 ex: -2//3 = -1
        
        return stack.pop()