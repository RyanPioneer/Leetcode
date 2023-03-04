"""
Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Date: 2023/3/4
Skill:
Runtime: 87 ms, faster than 72.58%
Memory Usage: 15.3 MB, less than 99.64%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = bisect_left(nums, target)
        right = bisect_right(nums, target)
        if left == right:
            return [-1, -1]
        else:
            return [left, right-1]
