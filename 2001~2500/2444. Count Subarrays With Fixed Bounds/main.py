"""
Source: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
Date: 2023/2/8
Skill:
Runtime: 846 ms, faster than 91.84%
Memory Usage: 28.7 MB, less than 43.37%
Time complexity:
Space complexity:
Constraints:
    2 <= nums.length <= 10^5
    1 <= nums[i], minK, maxK <= 10^6
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        minK_idx, maxK_idx, boundary, sz, res = -1, -1, -1, len(nums), 0

        for right in range(sz):
            if nums[right] > maxK or nums[right] < minK:
                maxK_idx, minK_idx, boundary = -1, -1, right
            if nums[right] == maxK:
                maxK_idx = right
            if nums[right] == minK:
                minK_idx = right
            if maxK_idx != -1 and minK_idx != -1:
                res += (min(maxK_idx, minK_idx) - boundary)

        return res


if __name__ == "__main__":
    s = Solution