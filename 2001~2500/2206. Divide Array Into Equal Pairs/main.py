"""
Source: https://leetcode.com/problems/divide-array-into-equal-pairs/
Date: 2022/12/5
Skill: 
Runtime: 237 ms, faster than 24.27%
Memory Usage: 14.1 MB, less than 61.47%
Time complexity: 
Space complexity: 
Constraints: 
    nums.length == 2 * n
    1 <= n <= 500
    1 <= nums[i] <= 500
"""

from typing import List

class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        my_dict = dict()
        for n in nums:
            if n in my_dict:
                my_dict[n] += 1
            else:
                my_dict[n] = 1
        for key, value in my_dict.items():
            if value%2 == 1:
                return False
        return True