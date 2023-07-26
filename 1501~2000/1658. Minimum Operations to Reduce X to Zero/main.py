"""
Source: https://rb.gy/rpd7y
Date: 2023/7/26
Skill:
Ref:
Runtime: TLE
Memory Usage:
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
    def minOperations(self, nums: List[int], x: int) -> int:
        sz, total = len(nums), sum(nums)
        if total < x:
            return -1
        if total == x:
            return sz
        dp = [[0 for _ in range(sz)] for _ in range(sz)]

        def find_res(left, right, target):
            if left > right:
                return -1
            if dp[left][right] != 0:
                return dp[left][right]
            if nums[left] > target and nums[right] > target:
                dp[left][right] = -1
                return -1
            if nums[left] == target or nums[right] == target:
                dp[left][right] = 1
                return 1
            step = sys.maxsize
            if nums[left] < target:
                step1 = find_res(left + 1, right, target - nums[left])
                if step1 != -1:
                    step = min(step, step1 + 1)
            if nums[right] < target:
                step2 = find_res(left, right - 1, target - nums[right])
                if step2 != -1:
                    step = min(step, step2 + 1)
            dp[left][right] = step if step < sys.maxsize else -1
            return dp[left][right]

        return find_res(0, sz - 1, x)


if __name__ == "__main__":
    s = Solution()
