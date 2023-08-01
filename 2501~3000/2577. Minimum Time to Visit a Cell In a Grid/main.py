"""
Source: https://rb.gy/bcirg
Date: 2023/8/1
Skill:
Ref:
Runtime: 3130 ms, faster than 19.05%
Memory Usage: 38.69 MB, less than 50.48%
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


class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        dirs, dist = [1, 0, -1, 0, 1], [[-1 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        heap, m, n = [[0, 0, 0]], len(grid), len(grid[0])
        heapify(heap)
        while heap:
            [time, x, y] = heappop(heap)
            if dist[x][y] != -1:
                continue
            dist[x][y] = time
            for i in range(4):
                next_x, next_y = x + dirs[i], y + dirs[i + 1]
                if not (0 <= next_x < m and 0 <= next_y < n) or dist[next_x][next_y] != -1:
                    continue
                if time + 1 >= grid[next_x][next_y]:
                    heappush(heap, [time + 1, next_x, next_y])
                else:
                    heappush(heap, [grid[next_x][next_y] + (grid[next_x][next_y] - time + 1) % 2, next_x, next_y])

        return dist[m - 1][n - 1]


if __name__ == "__main__":
    s = Solution()
