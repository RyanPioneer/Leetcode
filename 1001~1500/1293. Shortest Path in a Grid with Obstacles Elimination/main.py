"""
Source: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
Date: 2023/4/21
Skill:
Ref:
Runtime: 571 ms, faster than 48.23%
Memory Usage: 19.2 MB, less than 48.71%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 40
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        if m == 1 and n == 1:
            return 0
        visited = [[[False for _ in range(k + 1)] for _ in range(n)] for _ in range(m)]
        q, step, directions = deque([(0, 0, 0)]), 0, [0, 1, 0, -1, 0]
        visited[0][0][0] = True

        def check_available(x, y):
            return 0 <= x < m and 0 <= y < n

        while q:
            sz = len(q)
            for _ in range(sz):
                x, y, cross = q.popleft()
                for i in range(4):
                    next_x, next_y = x + directions[i], y + directions[i + 1]
                    if not check_available(next_x, next_y) or visited[next_x][next_y][cross]:
                        continue
                    if next_x == m - 1 and next_y == n - 1:
                        return step + 1
                    if grid[next_x][next_y] == 1:
                        if cross == k or visited[next_x][next_y][cross + 1]:
                            continue
                        else:
                            q.append((next_x, next_y, cross + 1))
                            visited[next_x][next_y][cross + 1] = True
                    else:
                        q.append((next_x, next_y, cross))
                        visited[next_x][next_y][cross] = True

            step += 1

        return -1


if __name__ == "__main__":
    s = Solution()
