"""
Source: https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/
Date: 2023/1/18
Skill: Greedy
Ref:
Runtime: 1017 ms, faster than 99.30%
Memory Usage: 28.9 MB, less than 55.94%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        res = 0
        for idx in range(len(nums)-1):
            if nums[idx] > nums[idx+1]: res += nums[idx] - nums[idx+1]

        return  res + nums[-1]