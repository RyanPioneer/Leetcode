"""
Source: https://leetcode.com/problems/two-sum/
Date: 2023/1/6
Skill:
Runtime: 90 ms, faster than 70.55%
Memory Usage: 15.1 MB, less than 50.8%
Time complexity:
Space complexity:
Constraints:
    Only one valid answer exists.
"""

from typing import List
from collections import defaultdict


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        myDict = defaultdict(int)
        for i in range(len(nums)):
            if target-nums[i] in myDict.keys():
                return [i, myDict[target-nums[i]]]
            myDict[nums[i]] = i