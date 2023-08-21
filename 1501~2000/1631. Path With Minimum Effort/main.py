"""
Source: https://rb.gy/xibtg
Date: 2023/8/21
Skill:
Ref:
Runtime: 519 ms, faster than 97.98%
Memory Usage: 17.64 MB, less than 88.70%
Time complexity:
Space complexity:
Constraints:
    1 <= rows, columns <= 100
    1 <= heights[i][j] <= 10 ** 6
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
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m, n, res, heap = len(heights), len(heights[0]), 0, [[0, 0, 0]]
        dirs = [0, 1, 0, -1, 0]
        heapify(heap)
        while heap:
            diff, x, y = heappop(heap)
            if heights[x][y] == -1:
                continue
            res = max(res, diff)
            if x == m - 1 and y == n - 1:
                return res
            for i in range(4):
                next_x, next_y = x + dirs[i], y + dirs[i + 1]
                if 0 <= next_x < m and 0 <= next_y < n and heights[next_x][next_y] != -1:
                    heappush(heap, [abs(heights[x][y] - heights[next_x][next_y]), next_x, next_y])
            heights[x][y] = -1

        return res


if __name__ == "__main__":
    s = Solution()
    heights = [[10, 8], [10, 8], [1, 2], [10, 3], [1, 3], [6, 3], [5, 2]]
    res = s.minimumEffortPath(heights)
