"""
Source: https://leetcode.com/problems/backspace-string-compare/
Date: 2023/1/23
Skill:
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


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def build(string):
            res = []
            for c in string:
                if c == "#":
                    if res:
                        res.pop()
                else:
                    res.append(c)

            return res

        return build(s) == build(t)