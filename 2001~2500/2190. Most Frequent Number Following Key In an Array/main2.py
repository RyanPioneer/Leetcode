"""
Source: https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/
Date: 2022/12/7
Skill: 
Runtime: 95 ms, faster than 85.37% 
Memory Usage: 14 MB, less than 93.17%
Time complexity: 
Space complexity: 
Constraints: 
    2 <= nums.length <= 1000
"""

from typing import List
from collections import defaultdict

class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        m = defaultdict(int)
        maxFreq = 0
        res = -1
        for i,n in enumerate(nums[:-1]):
            if n==key:
                m[nums[i+1]] += 1
                if m[nums[i+1]] > maxFreq:
                    maxFreq = m[nums[i+1]]
                    res = nums[i+1]
        return res