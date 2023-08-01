"""
Source: https://rb.gy/93w50
Date: 2023/8/1
Skill:
Ref:
Runtime: 41 ms, faster than 98.97%
Memory Usage: 16.15 MB, less than 95.86%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx, idx2 = len(nums) - 1, len(nums) - 1
        while idx - 1 >= 0 and nums[idx] <= nums[idx - 1]:
            idx -= 1
        if idx == 0:
            nums.sort()
            return
        idx -= 1
        while nums[idx2] <= nums[idx]:
            idx2 -= 1
        nums[idx], nums[idx2] = nums[idx2], nums[idx]
        nums[idx + 1:] = sorted(nums[idx + 1:])


if __name__ == "__main__":
    s = Solution()
