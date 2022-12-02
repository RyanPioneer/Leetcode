"""
Source: https://leetcode.com/problems/number-of-good-pairs/
Date: 2022/12/1
Skill: 
Runtime: 55 ms, faster than 67.24%
Memory Usage: 13.9 MB, less than 56.76%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 100
"""

from typing import List

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        res = 0
        mydict = dict()
        for n in nums:
            if n in mydict:
                res += mydict[n]
                mydict[n] += 1
            else:
                mydict[n] = 1
        return res