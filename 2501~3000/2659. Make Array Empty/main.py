"""
Source: https://rb.gy/q0i0n
Date: 2023/7/31
Skill: Fenwick tree (Binary indexed tree)
Ref: https://rb.gy/rugwh
Runtime: 3229 ms, faster than 10.06%
Memory Usage: 36.49 MB, less than 48.32%
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
    def __init__(self, n):
        self.bit_arr = [0 for _ in range(n + 1)]
        self.n = n

    def update_delta(self, idx, delta):
        while idx <= self.n:
            self.bit_arr[idx] += delta
            idx += idx & (-idx)

    def query_presum(self, idx):
        res = 0
        while idx > 0:
            res += self.bit_arr[idx]
            idx -= idx & (-idx)
        return res

    def get_sum_range(self, left, right):
        return self.query_presum(right) - self.query_presum(left - 1)


class Solution:
    def countOperationsToEmptyArray(self, nums: List[int]) -> int:
        bit, sz, res, idx_val, last_pos = BIT(len(nums)), len(nums), 0, [], 0
        for i in range(sz):
            idx_val.append([nums[i], i + 1])
            bit.update_delta(i + 1, 1)
        nums.insert(0, 0)
        idx_val.sort(key=lambda x: x[0])
        for i in range(len(idx_val)):
            pos = idx_val[i][1]
            if last_pos < pos:
                res += bit.get_sum_range(last_pos, pos)
            else:
                res += bit.get_sum_range(0, pos)
                res += bit.get_sum_range(last_pos + 1, sz)
            last_pos = pos
            bit.update_delta(pos, -1)

        return res


if __name__ == "__main__":
    s = Solution()
