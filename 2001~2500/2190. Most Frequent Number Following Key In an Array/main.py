"""
Source: https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/
Date: 2022/12/7
Skill: 
Runtime: 94 ms, faster than 85.61% 
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
        myDict = defaultdict(int)
        res = max_freq = 0
        for i in range(len(nums)-1):
            if nums[i] == key:
                myDict[nums[i+1]] += 1
                if myDict[nums[i+1]] > max_freq:
                    res = nums[i+1]
                    max_freq = myDict[nums[i+1]]
        return res