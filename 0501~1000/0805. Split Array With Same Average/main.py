"""
Source: https://rb.gy/qo4o1
Date: 2023/8/15
Skill:
Ref:
Runtime: MLE
Memory Usage:
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
        sz, avg = len(nums), sum(nums) / len(nums)

        @cache
        def dfs(cur_sum, cur_num, idx):
            nonlocal sz, avg
            if 0 < cur_num < sz and cur_sum / cur_num == avg:
                return True
            if idx == sz:
                return False
            if 0 < cur_num and cur_sum / cur_num > avg:
                return False
            if dfs(cur_sum + nums[idx], cur_num + 1, idx + 1):
                return True
            idx += 1
            while idx < sz and nums[idx] == nums[idx - 1]:
                idx += 1
            if dfs(cur_sum, cur_num, idx):
                return True
            return False

        return dfs(0, 0, 0)


if __name__ == "__main__":
    s = Solution()
