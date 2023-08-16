"""
Source: https://rb.gy/4mswu
Date: 2023/8/16
Skill:
Ref:
Runtime: 1143 ms, faster than 64.76%
Memory Usage: 29.16 MB, less than 90.95%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 200
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m, n, res = len(land), len(land[0]), []
        dirs = [0, -1, 0, 1, 0]

        def check_feasible(x, y):
            return 0 <= x < m and 0 <= y < n

        def bfs(x, y):
            r1, c1, r2, c2 = x, y, x, y
            q = deque([[x, y]])
            land[x][y] = 0
            while q:
                x, y = q.popleft()
                for i in range(4):
                    next_x, next_y = x + dirs[i], y + dirs[i + 1]
                    if check_feasible(next_x, next_y) and land[next_x][next_y] == 1:
                        if next_x > r2 or next_y > c2:
                            r2, c2 = next_x, next_y
                        land[next_x][next_y] = 0
                        q.append([next_x, next_y])
            res.append([r1, c1, r2, c2])

        for i in range(m):
            for j in range(n):
                if land[i][j] == 1:
                    bfs(i, j)
        return res


if __name__ == "__main__":
    s = Solution()
    land = [[1, 0, 0], [0, 1, 1], [0, 1, 1]]
    res = s.findFarmland(land)
