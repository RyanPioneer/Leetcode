"""
Source: https://leetcode.com/problems/count-increasing-quadruplets/
Date: 2023/8/9
Skill:
Runtime: TLE
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    4 <= nums.length <= 4000
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


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
    def countQuadruplets(self, nums: List[int]) -> int:
        sz, res = len(nums), 0
        smaller_before = BIT([0 for _ in range(sz + 1)])
        smaller_before.update_delta(nums[0], 1)
        for i in range(1, sz - 2):
            bigger_after = BIT([0 for _ in range(sz + 1)])
            bigger_after.update_delta(nums[-1], 1)
            for j in range(sz - 2, i, -1):
                if nums[i] > nums[j]:
                    smaller = smaller_before.query_range_sum(0, nums[j])
                    bigger = bigger_after.query_range_sum(nums[i], sz)
                    print(i, j, smaller, bigger)
                    res += smaller * bigger
                bigger_after.update_delta(nums[j], 1)
            smaller_before.update_delta(nums[i], 1)

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [1, 3, 5, 2, 4]
    res = s.countQuadruplets(nums)
    print(res)

