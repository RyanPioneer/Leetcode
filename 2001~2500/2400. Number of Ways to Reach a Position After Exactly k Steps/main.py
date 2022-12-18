"""
Source: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
Date: 2022/12/12
Skill: 
Runtime: 34 ms, faster than 95.13% 
Memory Usage: 13.9 MB, less than 88.69%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= startPos, endPos, k <= 1000
"""

from typing import List

class Solution:
    def numberOfWays(self, startPos: int, endPos: int, k: int) -> int:
        diff = abs(startPos-endPos)
        if diff > k or (k-diff)%2 == 1:
            return 0
        
        def cal(h, l):
            res = 1
            for i in range(l, h+1):
                res *= i
            return res
        
        return cal(k, diff+(k-diff)//2+1)//cal((k-diff)//2, 1)%(pow(10, 9)+7)