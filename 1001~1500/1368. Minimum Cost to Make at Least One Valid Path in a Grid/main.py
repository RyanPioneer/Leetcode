"""
Source: https://rb.gy/he79a
Date: 2023/7/24
Skill:
Ref:
Runtime: 332 ms, faster than 81.98%
Memory Usage: 17.45 MB, less than 82.56%
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
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visited, end_point = [[0 for _ in range(n)] for _ in range(m)], (m - 1, n - 1)
        dirs = defaultdict()
        dirs[1], dirs[2], dirs[3], dirs[4] = (0, 1), (0, -1), (1, 0), (-1, 0)
        visited[0][0] = 1

        def check_feasible(x, y):
            return 0 <= x < m and 0 <= y < n

        def bfs(x, y):
            q, res = deque([(x, y)]), []
            while q:
                cur_x, cur_y = q.popleft()
                res.append((cur_x, cur_y))
                dir1, dir2 = dirs[grid[cur_x][cur_y]]
                next_x, next_y = cur_x + dir1, cur_y + dir2
                if check_feasible(next_x, next_y) and visited[next_x][next_y] == 0:
                    visited[next_x][next_y] = 1
                    q.append((next_x, next_y))

            return res

        q, step = deque(), 0
        next_pos = bfs(0, 0)
        for i in next_pos:
            q.append(i)

        while q:
            sz = len(q)
            for _ in range(sz):
                cur_x, cur_y = q.popleft()
                if (cur_x, cur_y) == end_point:
                    return step
                for i in [1, 2, 3, 4]:
                    if i == grid[cur_x][cur_y]:
                        continue
                    next_x, next_y = cur_x + dirs[i][0], cur_y + dirs[i][1]
                    if check_feasible(next_x, next_y) and not visited[next_x][next_y]:
                        visited[next_x][next_y] = 1
                        next_pos = bfs(next_x, next_y)
                        for j in next_pos:
                            q.append(j)
            step += 1


if __name__ == "__main__":
    s = Solution()
