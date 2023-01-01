"""
Source: https://leetcode.com/problems/word-pattern/
Date: 2023/1/1
Skill:
Runtime: 29 ms, faster than 91.56%
Memory Usage: 13.9 MB, less than 74.33%
Time complexity:
Space complexity:
Constraints:
    1 <= pattern.length <= 300
    1 <= s.length <= 3000
    pattern contains only lower-case English letters.
    s contains only lowercase English letters and spaces ' '.
"""

from typing import List, Optional

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        dict, index, i = {}, 0, 0
        while i < len(s):
            word = s[i]
            while i+1 < len(s) and s[i+1] != ' ':
                i += 1
                word += s[i]
            if index == len(pattern): return False
            if pattern[index] in dict:
                if dict[pattern[index]] != word:
                    return False
            else:
                if word in dict.values():
                    return False
                dict[pattern[index]] = word
            index += 1
            i += 2
        if index != len(pattern): return False
        else: return True
