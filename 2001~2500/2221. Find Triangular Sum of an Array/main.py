"""
Source: https://rb.gy/y8oew
Date: 2023/8/5
Skill:
Ref:
Runtime: 1828 ms, faster than 88.33%
Memory Usage: 16.48 MB, less than 66.97%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while len(nums) > 1:
            nums2 = []
            for i in range(len(nums) - 1):
                nums2.append((nums[i] + nums[i + 1]) % 10)
            nums = nums2
        return nums[0]


if __name__ == "__main__":
    s = Solution()
