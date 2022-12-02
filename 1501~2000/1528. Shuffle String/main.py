"""
Source: https://leetcode.com/problems/shuffle-string/
Date: 2022/12/1
Skill: The join() method takes all items in an iterable and joins them into one string.
Runtime: 62 ms, faster than 86.87%
Memory Usage: 14 MB, less than 15.51%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        res = [""] * len(s)
        for i in range(len(s)):
            res[indices[i]] = s[i]
        return "".join(res)