"""
Source: https://leetcode.com/problems/add-binary/
Date: 2023/1/23
Skill:
Runtime: 29 ms, faster than 93.78%
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
        #* The bin() method returns the binary string equivalent to the given integer
        return bin(int(a, base=2) + int(b, base=2))[2:]