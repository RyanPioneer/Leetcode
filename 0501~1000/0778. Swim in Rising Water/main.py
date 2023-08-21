"""
Source: https://rb.gy/7k51l
Date: 2023/8/21
Skill:
Ref:
Runtime: 96 ms, faster than 88.48%
Memory Usage: 16.71 MB, less than 94.16%
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
from functools import cache


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n, heap, res = len(grid), [[grid[0][0], 0, 0]], 0
        heapify(heap)
        dirs = [0, 1, 0, -1, 0]
        while heap:
            height, x, y = heappop(heap)
            if grid[x][y] == -1:
                continue
            res = max(res, height)
            grid[x][y] = -1
            if x == n - 1 and y == n - 1:
                return res
            for i in range(4):
                next_x, next_y = x + dirs[i], y + dirs[i + 1]
                if 0 <= next_x < n and 0 <= next_y < n and grid[next_x][next_y] != -1:
                    heappush(heap, [grid[next_x][next_y], next_x, next_y])

        return res


if __name__ == "__main__":
    s = Solution()
