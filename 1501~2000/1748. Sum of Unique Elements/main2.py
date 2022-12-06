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
from collections import Counter

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        return sum(a for a,b in Counter(nums).items() if b == 1)