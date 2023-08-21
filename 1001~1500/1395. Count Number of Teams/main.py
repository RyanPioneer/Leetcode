"""
Source: https://rb.gy/8zug1
Date: 2023/8/21
Skill:
Ref:
Runtime: 416 ms, faster than 90.73%
Memory Usage: 18.63 MB, less than 7.30%
Time complexity:
Space complexity:
Constraints:
    3 <= rating.length <= 1000
    1 <= rating[i] <= 10 ** 5
    All the integers in rating are unique.
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right
from functools import cache


class BIT:
    def __init__(self, nums):
        self.nums = nums
        self.n = len(self.nums) - 1

    def update_delta(self, idx, delta):
        while idx <= self.n:
            self.nums[idx] += delta
            idx += (idx & -idx)

    def query(self, idx):
        total = 0
        while idx > 0:
            total += self.nums[idx]
            idx -= (idx & -idx)
        return total

    def query_range_sum(self, lo, hi):
        return self.query(hi) - self.query(lo - 1)


class Solution:
    def numTeams(self, rating: List[int]) -> int:
        smaller_before, larger_after, sz, res = [], [], len(rating), 0
        tree1, tree2 = BIT([0 for _ in range(10 ** 5 + 1)]), BIT([0 for _ in range(10 ** 5 + 1)])
        for i in range(sz):
            smaller_before.append(tree1.query_range_sum(1, rating[i]))
            tree1.update_delta(rating[i], 1)
            larger_after.append(tree2.query_range_sum(rating[sz - 1 - i], 10 ** 5))
            tree2.update_delta(rating[sz - 1 - i], 1)
        larger_after.reverse()
        for i in range(1, sz - 1):
            res += smaller_before[i] * larger_after[i] + (i - smaller_before[i]) * (sz - 1 - i - larger_after[i])
        return res


if __name__ == "__main__":
    s = Solution()
    rating = [2, 5, 3, 4, 1]
    res = s.numTeams(rating)
