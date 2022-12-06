"""
Source: https://leetcode.com/problems/sort-array-by-increasing-frequency/
Date: 2022/12/3
Skill: 
Runtime: 103 ms, faster than 55.80%
Memory Usage: 13.9 MB, less than 24.81%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 100
    -100 <= nums[i] <= 100
"""

from typing import List
from collections import Counter

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        return sorted(nums, key=lambda n: (cnt[n],-n))