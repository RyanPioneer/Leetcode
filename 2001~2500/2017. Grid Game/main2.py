"""
Source: https://rb.gy/lcnwy
Date: 2023/8/7
Skill:
Ref:
Runtime: 1161 ms, faster than 39.49%
Memory Usage: 32.99 MB, less than 30.57%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 5 * 10 ** 4
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        if n == 1:
            return 0
        presum, postsum = [[0 for _ in range(n)] for _ in range(2)], [[0 for _ in range(n)] for _ in range(2)]
        presum[0][0], presum[1][0] = grid[0][0], grid[1][0]
        postsum[0][-1], postsum[1][-1] = grid[0][-1], grid[1][-1]
        for i in range(1, n):
            for j in range(2):
                presum[j][i] = presum[j][i - 1] + grid[j][i]
                postsum[j][n - 1 - i] = postsum[j][n - i] + grid[j][n - 1 - i]

        res = min(presum[1][-2], postsum[0][1])
        for i in range(1, n - 1):
            res = min(res, max(presum[1][i - 1], postsum[0][i + 1]))
        return res


if __name__ == "__main__":
    s = Solution()
    grid = [[2, 5, 4], [1, 5, 1]]
    res = s.gridGame(grid)
    print(res)
