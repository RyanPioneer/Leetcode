"""
Source: https://rb.gy/61l4b
Date: 2023/7/24
Skill:
Ref:
Runtime: 2563 ms, faster than 15.73%
Memory Usage: 16.8 MB, less than 77.53%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 30
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        m, n, dirs = len(grid), len(grid[0]), [1, 0, -1, 0, 1]
        total = sum(sum(grid[i]) for i in range(m))
        if total <= 1:
            return total

        def check_feasible(x, y):
            return 0 <= x < m and 0 <= y < n

        def check_disconnected():
            visited, num = [[0 for _ in range(n)] for _ in range(m)], 0
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 0:
                        continue
                    if not visited[i][j]:
                        num += 1
                        if num > 1:
                            return True
                        visited[i][j] = 1
                        q = deque([(i, j)])
                        while q:
                            x, y = q.popleft()
                            for k in range(4):
                                next_x, next_y = x + dirs[k], y + dirs[k + 1]
                                if check_feasible(next_x, next_y) and grid[next_x][next_y] == 1 \
                                        and not visited[next_x][next_y]:
                                    q.append((next_x, next_y))
                                    visited[next_x][next_y] = 1
            return False

        if check_disconnected():
            return 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    continue
                grid[i][j] = 0
                if check_disconnected():
                    return 1
                grid[i][j] = 1

        return 2


if __name__ == "__main__":
    s = Solution()
    grid = [[0, 1, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]]
    res = s.minDays(grid)
