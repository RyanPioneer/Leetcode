"""
Source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Date: 2023/8/10
Skill:
Runtime: 53 ms, faster than 95.68%
Memory Usage: 17.08 MB, less than 11.93%
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
        sz = len(nums)
        while sz > 1 and nums[0] == nums[-1]:
            nums.pop()
            sz -= 1
        left, right = 0, sz - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            elif nums[mid] < target:
                if nums[right] < nums[mid]:
                    left = mid + 1
                else:
                    if nums[right] >= target:
                        left = mid + 1
                    else:
                        right = mid - 1
            else:
                if nums[right] >= nums[mid]:
                    right = mid - 1
                else:
                    if nums[right] >= target:
                        left = mid + 1
                    else:
                        right = mid - 1
        return False


if __name__ == "__main__":
    s = Solution()
