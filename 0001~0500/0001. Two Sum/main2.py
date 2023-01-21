"""
Source: https://leetcode.com/problems/two-sum/
Date: 2023/1/21
Skill:
Runtime: 60 ms, faster than 90.44%
Memory Usage: 15.2 MB, less than 21.4%
Time complexity:
Space complexity:
Constraints:
    Only one valid answer exists.
"""

from typing import List
from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        my_dict = defaultdict(int)
        for i in range(len(nums)):
            if target - nums[i] in my_dict:
                return [my_dict[target - nums[i]], i]
            my_dict[nums[i]] = i