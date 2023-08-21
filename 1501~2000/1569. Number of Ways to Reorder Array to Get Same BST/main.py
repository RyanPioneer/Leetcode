"""
Source: https://rb.gy/wuo2o
Date: 2023/8/21
Skill:
Ref:
Runtime: 2163 ms, faster than 67.31%
Memory Usage: 16.88 MB, less than 98.90%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
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
    def numOfWays(self, nums: List[int]) -> int:
        mod, n = 10 ** 9 + 7, len(nums)

        def divide_and_conquer(arr):
            if len(arr) == 1:
                return 1
            left, right, res, pos = [], [], 1, 1
            while pos < len(arr):





if __name__ == "__main__":
    s = Solution()
