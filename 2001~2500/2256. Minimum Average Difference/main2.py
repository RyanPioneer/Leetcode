"""
Source: https://leetcode.com/problems/minimum-average-difference/
Date: 2022/12/4
Skill: Prefix Sum Optimized
Runtime: 989 ms, faster than 97.47%
Memory Usage: 24.8 MB, less than 80.12%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^5
"""

from typing import List
import math

class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        res, sz, sum, prefix_sum, min_avg_diff = 0, len(nums), 0, 0, math.inf
        for n in nums:
            sum += n
        for i in range(sz):
            prefix_sum += nums[i]
            left_avg_sum, right_avg_sum = prefix_sum//(i+1), 0
            if i != sz-1:
                right_avg_sum = (sum-prefix_sum)//(sz-i-1)
            cur_diff = abs(left_avg_sum - right_avg_sum)
            if min_avg_diff > cur_diff:
                res = i
                min_avg_diff = cur_diff
        return res