"""
Source: https://leetcode.com/problems/detect-capital/description/
Date: 2023/1/2
Skill:
Runtime: 30 ms, faster than 92.94%
Memory Usage: 13.8 MB, less than 56.30%
Time complexity:
Space complexity:
Constraints:
    1 <= word.length <= 100
    word consists of lowercase and uppercase English letters.
"""

from typing import List
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        test = word.capitalize()
        if word.isupper() or word.islower() or test == word:
            return True
        else:
            return False