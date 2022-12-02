"""
Source: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
Date: 2022/12/1
Skill: 
Runtime: 79 ms, faster than 58.23%
Memory Usage: 13.9 MB, less than 84.16%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= sentences.length <= 100
    1 <= sentences[i].length <= 100
"""

from typing import List

class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        res = 0
        for s in sentences:
            num = 1
            for w in s:
                if w == ' ':
                    num += 1
            if num > res:
                res = num
        return res