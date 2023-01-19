"""
Source: https://leetcode.com/problems/maximum-subarray/description/
Date: 2023/1/18
Skill: Kadane's Algorithm
Ref:
Runtime: 803 ms, faster than 64.19%
Memory Usage: 28.5 MB, less than 33.14%
Time complexity:
Space complexity:
Constraints:
    -10^4 <= nums[i] <= 10^4
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        prev_res, res = nums[0], nums[0]
        for idx in range(1, len(nums)):
            prev_res = max(prev_res+nums[idx], nums[idx])
            res = max(res, prev_res)

        return res