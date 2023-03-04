"""
Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Date: 2023/3/4
Skill:
Runtime: 88 ms, faster than 67.41%
Memory Usage: 15.4 MB, less than 39.70%
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
        if len(nums) == 0:
            return [-1, -1]
        left, right, res = 0, len(nums) - 1, []
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid

        if nums[left] != target:
            res.append(-1)
        else:
            res.append(left)

        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right + 1) // 2
            if nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                left = mid

        if nums[right] != target:
            res.append(-1)
        else:
            res.append(right)

        return res
