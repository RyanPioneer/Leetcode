"""
Source: https://rb.gy/to82d
Date: 2023/8/19
Skill:
Ref:
Runtime: 4037 ms, faster than 44.44%
Memory Usage: 61.76 MB, less than 48.15%
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


class RangeSum:
    def __init__(self, nums):
        self.m, self.n = len(nums), len(nums[0])
        self.presum = [[0 for _ in range(self.n + 1)] for _ in range(self.m + 1)]
        self.presum[1][1] = nums[0][0]
        for i in range(1, self.n):
            self.presum[1][i + 1] = self.presum[1][i] + nums[0][i]
        for i in range(1, self.m):
            self.presum[i + 1][1] = self.presum[i][1] + nums[i][0]
        for i in range(2, self.m + 1):
            for j in range(2, self.n + 1):
                self.presum[i][j] = (self.presum[i - 1][j] + self.presum[i][j - 1] -
                                     self.presum[i - 1][j - 1] + nums[i - 1][j - 1])

    def query_range_sum(self, i, j, x, y):
        return self.presum[x + 1][y + 1] - self.presum[x + 1][j] - self.presum[i][y + 1] + self.presum[i][j]


class Solution:
    def possibleToStamp(self, grid: List[List[int]], stampHeight: int, stampWidth: int) -> bool:
        m, n = len(grid), len(grid[0])
        range_sum = RangeSum(grid)
        stamps = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(stampHeight - 1, m):
            for j in range(stampWidth - 1, n):
                if range_sum.query_range_sum(i - stampHeight + 1, j - stampWidth + 1, i, j) > 0:
                    stamps[i][j] = 0
                else:
                    stamps[i][j] = 1

        range_sum2 = RangeSum(stamps)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    continue
                a, b = min(m - 1, i + stampHeight - 1), min(n - 1, j + stampWidth - 1)
                if range_sum2.query_range_sum(i, j, a, b) == 0:
                    return False
        return True


if __name__ == "__main__":
    s = Solution()

