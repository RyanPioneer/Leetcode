"""
Source: https://leetcode.com/problems/maximum-sum-circular-subarray/
Date: 2023/1/18
Skill: Calculate the "Minimum Subarray"
Ref: https://reurl.cc/x1RQl5
Runtime: 543 ms, faster than 83.11%
Memory Usage: 19 MB, less than 43.34%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        prev_res, res, prev_min_res, min_res = nums[0], nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            prev_res = max(prev_res+nums[i], nums[i])
            res = max(res, prev_res)
            prev_min_res = min(prev_min_res+nums[i], nums[i])
            min_res = min(min_res, prev_min_res)

        return max(res, sum(nums)-min_res) if min_res != sum(nums) else min(nums)