"""
Source: https://leetcode.com/problems/sort-characters-by-frequency/
Date: 2022/12/3
Skill: 
Runtime: 72 ms, faster than 73.68%
Memory Usage: 15.2 MB, less than 81.15% 
Time complexity: 
Space complexity: 
Constraints: 
    1 <= s.length <= 5 * 10^5
    s consists of uppercase and lowercase English letters and digits.
"""

from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        cnt = Counter(s)
        res = []
        for key, value in sorted(cnt.items(), key = lambda item : item[1], reverse=True):
            res.append(key*value)
        return "".join(res)