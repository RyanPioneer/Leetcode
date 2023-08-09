"""
Source: https://rb.gy/dk44f
Date: 2023/8/9
Skill:
Ref:
Runtime: 5254 ms, faster than 30.66%
Memory Usage: 30.44 MB, less than 93.43%
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


class BIT:
    def __init__(self, nums):
        self.nums = nums
        self.n = len(nums) - 1

    def query_sum(self, idx):
        num = 0
        while idx > 0:
            num += self.nums[idx]
            idx -= idx & (-idx)
        return num

    def update_delta(self, idx, delta):
        while idx <= self.n:
            self.nums[idx] += delta
            idx += idx & (-idx)

    def query_range_sum(self, left, right):
        return self.query_sum(right) - self.query_sum(left - 1)


class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        tree, mod, res = BIT([0 for _ in range(10 ** 5 + 1)]), 10 ** 9 + 7, 0
        cur_min, cur_max, sz = instructions[0], instructions[0], len(instructions)
        tree.update_delta(instructions[0], 1)
        for i in range(1, sz):
            less, greater = 0, 0
            if instructions[i] > cur_min:
                less = tree.query_range_sum(cur_min, instructions[i] - 1)
            else:
                cur_min = instructions[i]
            if instructions[i] < cur_max:
                greater = tree.query_range_sum(instructions[i] + 1, cur_max)
            else:
                cur_max = instructions[i]
            res += min(less, greater)
            tree.update_delta(instructions[i], 1)
        return res % mod


if __name__ == "__main__":
    s = Solution()
