"""
Source: https://leetcode.com/problems/running-sum-of-1d-array/
Date: 2022/12/1
Skill: 
Runtime: 81 ms, faster than 45.07% 
Memory Usage: 13.9 MB, less than 93.73%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 1000
    -10^6 <= nums[i] <= 10^6
"""

from typing import List
from itertools import accumulate

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        return accumulate(nums)   