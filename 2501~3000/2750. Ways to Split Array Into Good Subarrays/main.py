"""
Source: https://rb.gy/zpq6p
Date: 2023/7/10
Skill:
Ref:
Runtime: 2418 ms, faster than 41.69%
Memory Usage: 19.6 MB, less than 91.49%
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
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        if sum(nums) == 0:
            return 0
        MOD, res, left, sz = 10 ** 9 + 7, 1, 0, len(nums)
        while left < sz and nums[left] == 0:
            left += 1
        while left < sz:
            while left < sz and nums[left] == 1:
                left += 1
            if left == sz:
                break
            zero_num = 0
            while left < sz and nums[left] == 0:
                zero_num += 1
                left += 1
            if left == sz:
                break
            res *= zero_num + 1
        return res % MOD


if __name__ == "__main__":
    s = Solution()
