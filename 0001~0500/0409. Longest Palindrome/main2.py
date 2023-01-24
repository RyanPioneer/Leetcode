"""
Source: https://leetcode.com/problems/longest-palindrome/
Date: 2023/1/23
Skill:
Runtime: 34 ms, faster than 77.46%
Memory Usage: 13.7 MB, less than 96.90%
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

class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt, res = Counter(s), 0
        for c, freq in cnt.items():
            res += freq//2*2
            if freq%2 and not res%2:
                res += 1

        return res