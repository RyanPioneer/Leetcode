"""
Source: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
Date: 2023/1/20
Skill:
Ref:
Runtime: 81 ms, faster than 71.31%
Memory Usage: 15.2 MB, less than 81.97%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^4
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        res, cur_num = 1, 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]: cur_num += 1
            else:
                res = max(res, cur_num)
                cur_num = 1

        return max(res, cur_num)