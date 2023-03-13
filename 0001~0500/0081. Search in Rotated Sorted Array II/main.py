"""
Source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Date: 2023/3/13
Skill:
Runtime: 61 ms, faster than 31.96%
Memory Usage: 14.4 MB, less than 49.65%
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
    def search(self, nums: List[int], target: int) -> bool:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            while left < mid and nums[left] == nums[mid]:   # ! key!
                left += 1
            if left == mid:
                left = mid + 1
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
            return True
        else:
            return False


if __name__ == "__main__":
    s = Solution()
