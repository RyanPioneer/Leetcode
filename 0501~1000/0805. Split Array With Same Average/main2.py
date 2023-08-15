"""
Source: https://rb.gy/qo4o1
Date: 2023/8/15
Skill:
Ref:
Runtime: 880 ms, faster than 43.66%
Memory Usage: 220.66 MB, less than 8.63%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 30
    0 <= nums[i] <= 10 ** 4
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right
from functools import cache


class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        nums.sort()
        sz, total = len(nums), sum(nums)

        @cache
        def dfs(target, number, idx):
            nonlocal sz
            if number == 0:
                return target == 0
            if idx == sz:
                return False
            if nums[idx] > target / number:
                return False
            if dfs(target - nums[idx], number - 1, idx + 1):
                return True
            idx += 1
            while idx < sz and nums[idx] == nums[idx - 1]:
                idx += 1
            if dfs(target, number, idx):
                return True
            return False

        for i in range(1, sz):
            if total * i % sz != 0:
                continue
            if dfs(total * i // sz, i, 0):
                return True
        return False


if __name__ == "__main__":
    s = Solution()
