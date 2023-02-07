"""
Source: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
Date: 2023/2/7
Skill:
Runtime: 32 ms, faster than 84.4%
Memory Usage: 13.8 MB, less than 69.62%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 1000
    1 <= part.length <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            s = s.replace(part, "", 1)
        return s


if __name__ == "__main__":
    s = Solution