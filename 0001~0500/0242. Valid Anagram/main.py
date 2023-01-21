"""
Source: https://leetcode.com/problems/valid-anagram/
Date: 2023/1/21
Skill:
Runtime: 52 ms, faster than 73.97%
Memory Usage: 15 MB, less than 21.75%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length, t.length <= 5 * 10^4
"""

from typing import List
from collections import defaultdict

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)