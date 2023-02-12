"""
Source: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
Date: 2023/2/12
Skill:
Runtime: 45 ms, faster than 83.26%
Memory Usage: 13.9 MB, less than 70.33%
Time complexity:
Space complexity:
Constraints:
    2 <= nums.length <= 1000
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        start, res, sz = nums[0], -1, len(nums)
        for i in range(1, sz):
            if nums[i] < nums[i-1]:
                start = min(start, nums[i])
            elif nums[i] > nums[i-1]:
                res = max(nums[i] - start, res)

        return res


if __name__ == "__main__":
    s = Solution