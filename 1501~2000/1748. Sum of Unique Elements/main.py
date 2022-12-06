"""
Source: https://leetcode.com/problems/sum-of-unique-elements/
Date: 2022/12/2
Skill: 
Runtime: 59 ms, faster than 65.12%
Memory Usage: 13.8 MB, less than 54.75%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 100
    1 <= nums[i] <= 100
"""

from typing import List

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        numset, unique, res = set(), set(), 0
        for n in nums:
            if n in numset and n in unique:
                unique.remove(n)
            elif n not in numset:
                numset.add(n)
                unique.add(n)
        for n in unique:
            res += n
        return res
                