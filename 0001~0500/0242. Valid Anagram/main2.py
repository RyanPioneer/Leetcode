"""
Source: https://leetcode.com/problems/valid-anagram/
Date: 2023/1/21
Skill:
Runtime: 53 ms, faster than 71%
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
        dict1, dict2 = defaultdict(int), defaultdict(int)
        for c in s:
            dict1[c] += 1
        for c in t:
            dict2[c] += 1
        return dict1 == dict2