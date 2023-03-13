"""
Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Date: 2023/3/13
Skill:
Runtime: 37 ms, faster than 90.49%
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
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        return nums[left]


if __name__ == "__main__":
    s = Solution()
    nums = [3, 4, 5, 1, 2]
    res = s.findMin(nums)
