"""
Source: https://leetcode.com/problems/divide-array-into-equal-pairs/
Date: 2022/12/5
Skill: 
Runtime: 
Memory Usage: 
Time complexity: 207 ms, faster than 46.50% 
Space complexity: 14.1 MB, less than 61.47% 
Constraints: 
    nums.length == 2 * n
    1 <= n <= 500
    1 <= nums[i] <= 500
"""

from typing import List
from collections import Counter

class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        cnt = Counter(nums)
        for key, value in cnt.items():
            if value%2 == 1:
                return False
        return True