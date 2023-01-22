"""
Source: https://leetcode.com/problems/palindrome-partitioning/
Date: 2023/1/22
Skill:
Runtime: 917 ms, faster than 38.9%
Memory Usage: 41.3 MB, less than 5.29%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 16
    s contains only lowercase English letters.
"""

from typing import List
from functools import lru_cache, cache

class Solution:
    @lru_cache(None)
    def partition(self, s: str) -> List[List[str]]:
        if not s: return [[]]
        res = []
        for i in range(1, len(s)+1):
            if s[:i] == s[:i][::-1]:
                for j in self.partition(s[i:]):
                    res.append([s[:i]] + j)

        return res