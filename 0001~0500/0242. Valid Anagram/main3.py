"""
Source: https://leetcode.com/problems/valid-anagram/
Date: 2023/1/21
Skill:
Runtime: 64 ms, faster than 43.63%
Memory Usage: 14.5 MB, less than 33.80%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length, t.length <= 5 * 10^4
"""

from typing import List
from collections import defaultdict


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        dict1, dict2 = [0 for _ in range(26)], [0 for _ in range(26)]
        for i in range(len(s)):
            dict1[ord(s[i]) - ord("a")] += 1
            dict2[ord(t[i]) - ord("a")] += 1

        return dict1 == dict2