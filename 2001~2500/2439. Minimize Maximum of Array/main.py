"""
Source: https://leetcode.com/problems/minimize-maximum-of-array/
Date: 2023/3/24
Skill: Binary search
Runtime: 1394 ms, faster than 27.7%
Memory Usage: 26.8 MB, less than 42.36%
Time complexity:
Space complexity:
Constraints:
    2 <= nums.length <= 10^5
    0 <= nums[i] <= 10^9
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        low, high, sz = nums[0], max(nums), len(nums)
        while low < high:
            mid = (low + high) // 2
            buffer = 0
            for i in range(sz):
                buffer += mid - nums[i]
                if buffer < 0:
                    break
            if buffer < 0:
                low = mid + 1
            else:
                high = mid

        return low


if __name__ == "__main__":
    s = Solution()
