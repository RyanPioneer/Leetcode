"""
Source: https://leetcode.com/problems/search-in-rotated-sorted-array/
Date: 2023/3/13
Skill:
Runtime: 42 ms, faster than 73.8%
Memory Usage: 14.3 MB, less than 12.34%
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
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                if nums[left] <= target or nums[left] > nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < nums[left] <= target:
                    right = mid - 1
                else:
                    left = mid + 1

        if nums[left] == target:
            return left
        else:
            return -1


if __name__ == "__main__":
    s = Solution()
    nums = [4, 5, 6, 7, 0, 1, 2]
    target = 0
