"""
Source: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
Date: 2022/12/7
Skill: 
Runtime: 45 ms, faster than 73.67% 
Memory Usage: 13.8 MB, less than 57.43%
Time complexity: 
Space complexity: 
Constraints: 
    1000 <= num <= 9999
"""

from typing import List

class Solution:
    def minimumSum(self, num: int) -> int:
        s = [int(x) for x in str(num)]
        s.sort()
        return (s[0]+s[1])*10+(s[2]+s[3])