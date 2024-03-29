"""
Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Date: 2023/3/13
Skill:
Runtime: 48 ms, faster than 28.94%
Memory Usage: 14.1 MB, less than 92.70%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right, sz = 0, len(nums) - 1, len(nums)
        if len(nums) <= 2:
            return min(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < nums[(mid + 1) % sz] < nums[(mid - 1 + sz) % sz]:
                return nums[mid]
            if nums[left] < nums[mid] < nums[right] or nums[left] > nums[right] > nums[mid]:
                right = mid - 1
            else:
                left = mid + 1

        return nums[left]


if __name__ == "__main__":
    s = Solution()
    nums = [3, 4, 5, 1, 2]
    res = s.findMin(nums)
