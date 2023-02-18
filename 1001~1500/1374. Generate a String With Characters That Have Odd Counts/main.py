"""
Source: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
Date: 2023/2/18
Skill:
Runtime: 28 ms, faster than 83.33%
Memory Usage: 13.8 MB, less than 43.30%
Time complexity:
Space complexity:
Constraints:
    The returned string must contain only lowercase English letters.
    1 <= n <= 500
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def generateTheString(self, n: int) -> str:
        return "a" * n if n%2 == 1 else "a" * (n-1) + "b"


if __name__ == "__main__":
    s = Solution