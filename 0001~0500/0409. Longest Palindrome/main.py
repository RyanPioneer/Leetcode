"""
Source: https://leetcode.com/problems/longest-palindrome/
Date: 2023/1/23
Skill:
Runtime: 66 ms, faster than 16.97%
Memory Usage: 14 MB, less than 17.63%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 2000
    s consists of lowercase and/or uppercase English letters only.
"""

import math
from typing import List
from collections import defaultdict, Counter
from functools import lru_cache, cache
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools

@functools.total_ordering
class Element:
    def __init__(self, c, count):
        self.c = c
        self.count = count

    def __lt__(self, other):
        return self.count < other.count

    def __eq__(self, other):
        return self.count == other.count and self.c == other.c

class Solution:
    def longestPalindrome(self, s: str) -> int:
        heap, cnt, res, mid = [], Counter(s), 0, 0
        heapify(heap)
        for c, freq in cnt.items():
            heappush(heap, (Element(c, freq), c))

        while heap:
            e = heappop(heap)[0]
            if e.count%2:
                if not mid:
                    mid = 1
                    res += 1
                res += e.count-1
            else:
                res += e.count

        return res