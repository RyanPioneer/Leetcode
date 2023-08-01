"""
Source: https://rb.gy/ef6hs
Date: 2023/8/1
Skill:
Ref:
Runtime: 60 ms, faster than 95.89%
Memory Usage: 16.57 MB, less than 49.77%
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
        self.n = n
        self.bit_arr = [0 for _ in range(n + 1)]

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

    def get_range_sum(self, left, right):
        return self.query_presum(right) - self.query_presum(left - 1)


class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        res, bit, num2pos, left = [], BIT(2 * m + 1), defaultdict(int), m
        for i in range(m):
            bit.update_delta(m + 1 + i, 1)
            num2pos[i + 1] = m + 1 + i
        for query in queries:
            num = bit.query_presum(num2pos[query])
            res.append(num - 1)
            bit.update_delta(num2pos[query], -1)
            num2pos[query] = left
            left -= 1
            bit.update_delta(num2pos[query], 1)

        return res


if __name__ == "__main__":
    s = Solution()
    queries, m = [4, 1, 2, 2], 4
    res = s.processQueries(queries, m)
