"""
Source: https://rb.gy/yhd2u
Date: 2023/8/25
Skill:
Runtime: 2709 ms, faster than 71.36%
Memory Usage: 24.03 MB, less than 95.62%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 500
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n, dirs, res = len(grid), [0, 1, 0, -1, 0], 0
        land_idx, land_num, land_size = [[-1 for _ in range(n)] for _ in range(n)], 0, defaultdict(int)

        def check_feasible(x, y):
            return 0 <= x < n and 0 <= y < n

        def dfs(x, y, idx):
            nonlocal res
            q, num, land_idx[x][y] = deque([[x, y]]), 1, idx
            while q:
                x, y = q.popleft()
                for i in range(4):
                    next_x, next_y = x + dirs[i], y + dirs[i + 1]
                    if check_feasible(next_x, next_y) and grid[next_x][next_y] == 1 and land_idx[next_x][next_y] == -1:
                        q.append([next_x, next_y])
                        num += 1
                        land_idx[next_x][next_y] = idx

            land_size[idx] = num
            res = max(res, num)

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1 and land_idx[i][j] == -1:
                    dfs(i, j, land_num)
                    land_num += 1

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    land, num = set(), 0
                    for k in range(4):
                        x, y = i + dirs[k], j + dirs[k + 1]
                        if check_feasible(x, y) and grid[x][y] == 1 and land_idx[x][y] not in land:
                            num += land_size[land_idx[x][y]]
                            land.add(land_idx[x][y])
                    res = max(res, num + 1)

        return res


if __name__ == "__main__":
    s = Solution()
    grid = [[1, 1], [1, 1]]
    res = s.largestIsland(grid)
    print(res)
