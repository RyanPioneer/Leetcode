"""
Source: https://leetcode.com/problems/add-binary/
Date: 2023/1/23
Skill:
Runtime: 39 ms, faster than 60.11%
Memory Usage: 13.8 MB, less than 66.37%
Time complexity:
Space complexity:
Constraints:
    1 <= a.length, b.length <= 10^4
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry, res = 0, ""
        a, b = list(a), list(b)
        while a or b or carry:
            if a:
                carry += int(a.pop())
            if b:
                carry += int(b.pop())
            res += str(carry%2)
            carry //= 2

        return res[::-1]