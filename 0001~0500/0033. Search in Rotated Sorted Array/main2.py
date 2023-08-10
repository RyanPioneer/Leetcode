"""
Source: https://leetcode.com/problems/search-in-rotated-sorted-array/
Date: 2023/8/10
Skill:
Runtime: 50 ms, faster than 73.41%
Memory Usage: 16.71 MB, less than 37.38%
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
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                if nums[right] < nums[mid]:
                    left = mid + 1
                else:
                    if nums[right] >= target:
                        left = mid + 1
                    else:
                        right = mid - 1
            else:
                if nums[right] > nums[mid]:
                    right = mid - 1
                else:
                    if nums[right] >= target:
                        left = mid + 1
                    else:
                        right = mid - 1
        return -1


if __name__ == "__main__":
    s = Solution()
