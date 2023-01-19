"""
Source: https://leetcode.com/problems/maximum-sum-circular-subarray/
Date: 2023/1/18
Skill: Enumerate prefix and suffix sums
Ref:
Runtime: 618 ms, faster than 52.8%
Memory Usage: 18.9 MB, less than 73.46%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
import math

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        prev_res, res, sz = -math.inf, -math.inf, len(nums)
        right_max, right_sum, left_sum = [nums[sz-1] for _ in range(sz)], nums[sz-1], 0

        for i in range(sz-2, -1, -1):
            right_sum += nums[i]
            right_max[i] = max(right_max[i+1], right_sum)

        for i in range(sz):
            prev_res = max(prev_res+nums[i], nums[i])
            left_sum += nums[i]
            res = max(res, prev_res)
            if i < sz-1: res = max(res, left_sum+right_max[i+1])

        return res