"""
Source: https://leetcode.com/problems/valid-parentheses/
Date: 2023/1/21
Skill:
Runtime: 28 ms, faster than 91.82%
Memory Usage: 13.8 MB, less than 65.97%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10^4
"""

from typing import List
from collections import defaultdict

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        my_dict = {')':'(', '}':'{', ']':'['}
        left_par = {'(', '{', '['}
        for c in s:
            if c in left_par:
                stack.append(c)
            else:
                if len(stack) != 0 and stack[-1] == my_dict[c]: stack.pop()
                else: return False

        if len(stack) != 0: return False
        else: return True