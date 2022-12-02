"""
Source: https://leetcode.com/problems/determine-if-two-strings-are-close/
Date: 2022/12/2
Skill: 
Runtime: 141 ms, faster than 97.60%
Memory Usage: 15.3 MB, less than 43.60% 
Time complexity: 
Space complexity: 
Constraints: 
    1 <= word1.length, word2.length <= 10^5
    word1 and word2 contain only lowercase English letters.
"""

from typing import List
from collections import Counter

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        return set(word1) == set(word2) and Counter(Counter(word1).values())\
                == Counter(Counter(word2).values())