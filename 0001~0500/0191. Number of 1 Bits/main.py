"""
Source: https://leetcode.com/problems/number-of-1-bits/description/
Date: 2023/1/25
Skill:
Runtime: 34 ms, faster than 71.90%
Memory Usage: 13.9 MB, less than 45.57%
Time complexity:
Space complexity:
Constraints:
    The input must be a binary string of length 32.
"""

import math
from typing import List
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def hammingWeight(self, n: int) -> int:
        return sum(n & 1<<i != 0 for i in range(32))