"""
Source: https://rb.gy/541r6
Date: 2023/7/17
Skill: Binary Indexed Tree
Ref: https://rb.gy/rs674
Runtime: 1698 ms, faster than 78.33%
Memory Usage: 33.42 MB, less than 85.21%
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


class FenwickTree:
    def __init__(self, n):
        self.nums = [0 for i in range(n+1)]

    def update(self, i, delta):
        while i < len(self.nums):
            self.nums[i] += delta
            i += i & -i

    def query(self, i):
        sum = 0
        while i > 0:
            sum += self.nums[i]
            i -= i & -i
        return sum


class NumArray:

    def __init__(self, nums: List[int]):
        self.BIT = FenwickTree(len(nums))
        self.nums = nums
        for i in range(len(nums)):
            self.BIT.update(i+1, nums[i])

    def update(self, index: int, val: int) -> None:
        self.BIT.update(index + 1, val - self.nums[index])
        self.nums[index] = val

    def sumRange(self, left: int, right: int) -> int:
        return self.BIT.query(right+1) - self.BIT.query(left)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)

if __name__ == "__main__":
    s = NumArray()

