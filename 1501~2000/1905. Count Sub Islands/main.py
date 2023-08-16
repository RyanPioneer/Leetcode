"""
Source: https://rb.gy/f7g3x
Date: 2023/8/16
Skill:
Ref:
Runtime: 2494 ms, faster than 90.77%
Memory Usage: 24.07 MB, less than 97.95%
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
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m, n, res, dirs = len(grid1), len(grid1[0]), 0, [0, 1, 0, -1, 0]

        def check_feasible(x, y):
            return 0 <= x < m and 0 <= y < n

        def bfs(x, y):
            nonlocal res
            if grid1[x][y] == 0:
                return
            grid2[x][y], q, flag = 0, deque([[x, y]]), True
            while q:
                x, y = q.popleft()
                for i in range(4):
                    next_x, next_y = x + dirs[i], y + dirs[i + 1]
                    if check_feasible(next_x, next_y) and grid2[next_x][next_y] == 1:
                        if grid1[next_x][next_y] == 0:
                            flag = False
                        grid2[next_x][next_y] = 0
                        q.append([next_x, next_y])
            if flag:
                res += 1

        for i in range(m):
            for j in range(n):
                if grid2[i][j] == 1:
                    bfs(i, j)
        return res


if __name__ == "__main__":
    s = Solution()
