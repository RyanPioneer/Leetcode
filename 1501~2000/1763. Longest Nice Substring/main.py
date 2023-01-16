"""
Source: https://leetcode.com/problems/longest-nice-substring/
Date: 2023/1/16
Skill: Divide and Conquer
Ref:
Runtime: 28 ms, faster than 97.80%
Memory Usage: 13.9 MB, less than 34.7%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        if len(s) < 2: return ""
        letters = set(s)
        for i, l in enumerate(s):
            if l.swapcase() not in letters:
                left, right = self.longestNiceSubstring(s[:i]), self.longestNiceSubstring(s[i+1:])
                return left if len(left) >= len(right) else right

        return s