"""
Source: https://leetcode.com/problems/greatest-common-divisor-of-strings/
Date: 2023/2/1
Skill:
Runtime: 26 ms, faster than 96.89%
Memory Usage: 13.9 MB, less than 70.81%
Time complexity:
Space complexity:
Constraints:
    1 <= str1.length, str2.length <= 1000
    str1 and str2 consist of English uppercase letters.
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1, len2 = len(str1), len(str2)

        def check_valid(sub):
            if len1%len(sub) or len2%len(sub): return False
            num1, num2 = len1//len(sub), len2//len(sub)
            return str1 == sub * num1 and str2 == sub * num2

        for i in range(min(len1, len2), 0, -1):
            if check_valid(str1[:i]):
                return str1[:i]

        return ""