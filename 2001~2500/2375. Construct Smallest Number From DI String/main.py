"""
Source: https://leetcode.com/problems/construct-smallest-number-from-di-string/
Date: 2023/2/18
Skill:
Ref:
Runtime: 32 ms, faster than 80.72%
Memory Usage: 13.8 MB, less than 94.46%
Time complexity:
Space complexity:
Constraints:
    1 <= pattern.length <= 8
    pattern consists of only the letters 'I' and 'D'.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def smallestNumber(self, pattern: str) -> str:
        res, num = [], 0


if __name__ == "__main__":
    s = Solution