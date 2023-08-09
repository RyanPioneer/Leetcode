"""
Source: https://rb.gy/f4wh2
Date: 2023/8/9
Skill:
Runtime: 451 ms, faster than 18.74%
Memory Usage: 36.71 MB, less than 7.62%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 2 * 10 ** 5
"""

import math
import sys
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        sz = len(nums)
        smallest_before, monotonic_stack = [sys.maxsize for _ in range(sz)], [sz - 1]
        for i in range(1, sz):
            smallest_before[i] = min(nums[i - 1], smallest_before[i - 1])
        for i in range(sz - 2, 0, -1):
            next_min = -sys.maxsize
            while monotonic_stack and nums[monotonic_stack[-1]] < nums[i]:
                next_min = nums[monotonic_stack[-1]]
                monotonic_stack.pop()
            if next_min > smallest_before[i]:
                return True
            monotonic_stack.append(i)
        return False


if __name__ == "__main__":
    s = Solution()

