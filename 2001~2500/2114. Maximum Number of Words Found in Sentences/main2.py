"""
Source: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
Date: 2022/12/1
Skill: 
Runtime: 65 ms, faster than 72.52%
Memory Usage: 13.9 MB, less than 84.16%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= sentences.length <= 100
    1 <= sentences[i].length <= 100
"""

from typing import List

class Solution:
    def mostWordsFound(self, ss: List[str]) -> int:
        return max(s.count(" ") for s in ss) + 1