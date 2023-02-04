"""
Source: https://leetcode.com/problems/minimum-size-subarray-sum/
Date: 2023/2/4
Skill: Sliding Window
Runtime: 245 ms, faster than 97.12%
Memory Usage: 27.1 MB, less than 85.24%
Time complexity:
Space complexity:
Constraints:
    1 <= nums[i] <= 10^4
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        start, end, res, sz, cur_sum = 0, 0, math.inf, len(nums), 0
        while end < sz:
            cur_sum += nums[end]
            if cur_sum >= target:
                while cur_sum - nums[start] >= target:
                    cur_sum -= nums[start]
                    start += 1
                res = min(end-start+1, res)

            end += 1

        return res if res != math.inf else 0