"""
Source: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/description/
Date: 2023/1/16
Skill:
Ref:
Runtime: 36 ms, faster than 98.4%
Memory Usage: 14.8 MB, less than 99.51%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        quotient, remainder = divmod(k-n, 25)
        if remainder == 0:
            return "a" * (n-quotient) + "z" * quotient
        else:
            return "a" * (n-quotient-1) + chr(ord("a")+remainder) + "z" * quotient