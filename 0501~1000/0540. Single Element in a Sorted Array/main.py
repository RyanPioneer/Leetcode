"""
Source: https://leetcode.com/problems/single-element-in-a-sorted-array/
Date: 2023/2/21
Skill:
Ref:
Runtime: 168 ms, faster than 92.86%
Memory Usage: 23.8 MB, less than 39.30%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        if len(nums) == 1: return nums[0]
        start, end, sz = 0, len(nums) - 1, len(nums)
        while 1:
            mid = (start + end) // 2
            if mid == 0:
                if nums[mid] != nums[mid + 1]:
                    return nums[mid]
                else:
                    start = mid + 2
            elif mid == sz-1:
                if nums[mid] != nums[mid - 1]:
                    return nums[mid]
                else:
                    end = mid - 2
            else:
                if nums[mid] != nums[mid + 1] and nums[mid] != nums[mid - 1]:
                    return nums[mid]
                else:
                    if mid % 2 == 0:
                        if nums[mid] == nums[mid + 1]:
                            start = mid + 2
                        else:
                            end = mid - 2
                    else:
                        if nums[mid] == nums[mid - 1]:
                            start = mid + 2
                        else:
                            end = mid - 2


if __name__ == "__main__":
    s = Solution