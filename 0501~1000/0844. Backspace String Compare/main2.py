"""
Source: https://leetcode.com/problems/backspace-string-compare/
Date: 2023/1/23
Skill: Two Pointer
Runtime: 29 ms, faster than 90.42%
Memory Usage: 13.8 MB, less than 66.28%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length, t.length <= 200
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution(object):
    def backspaceCompare(self, s: str, t: str) -> bool:
        r1 = len(s) - 1
        r2 = len(t) - 1

        while r1 >= 0 or r2 >= 0:
            char1 = char2 = ""
            if r1 >= 0:
                char1, r1 = self.getChar(s, r1)
            if r2 >= 0:
                char2, r2 = self.getChar(t, r2)
            if char1 != char2:
                return False
        return True

    def getChar(self, s, r):
        char, count = '', 0
        while r >= 0 and not char:
            if s[r] == '#':
                count += 1
            elif count == 0:
                char = s[r]
            else:
                count -= 1
            r -= 1
        return char, r