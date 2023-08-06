"""
Source: https://rb.gy/nv0qv
Date: 2023/8/6
Skill:
Ref:
Runtime: 3794 ms, faster than 5.56%
Memory Usage: 25.14 MB, less than 100.00%
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
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        sz, dirs = len(grid), [0, 1, 0, -1, 0]
        if grid[0][0] == 1 or grid[-1][-1] == 1:
            return 0
        dist, q = [[-1 for _ in range(sz)] for _ in range(sz)], deque()
        for i in range(sz):
            for j in range(sz):
                if grid[i][j] == 1:
                    q.append([i, j, 0])
                    dist[i][j] = 0

        def check_feasible(a, b):
            return 0 <= a < sz and 0 <= b < sz

        while q:
            [x, y, dis] = q.popleft()
            for i in range(4):
                next_x, next_y = x + dirs[i], y + dirs[i + 1]
                if check_feasible(next_x, next_y) and dist[next_x][next_y] == -1:
                    dist[next_x][next_y] = dis + 1
                    q.append([next_x, next_y, dis + 1])

        heap, res, visited = [[-dist[0][0], 0, 0]], dist[0][0], [[0 for _ in range(sz)] for _ in range(sz)]
        heapify(heap)
        while heap:
            [dis, x, y] = heappop(heap)
            if x == sz - 1 and y == sz - 1:
                return res
            if visited[x][y] == 1:
                continue
            visited[x][y] = 1
            res = min(res, -dis)
            for i in range(4):
                next_x, next_y = x + dirs[i], y + dirs[i + 1]
                if check_feasible(next_x, next_y) and visited[next_x][next_y] == 0:
                    heappush(heap, [-dist[next_x][next_y], next_x, next_y])


if __name__ == "__main__":
    s = Solution()
