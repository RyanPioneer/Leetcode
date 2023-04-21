"""
Source: https://leetcode.com/problems/detect-cycles-in-2d-grid/
Date: 2023/4/21
Skill:
Ref:
Runtime: 2319 ms, faster than 56.25%
Memory Usage: 22.7 MB, less than 96.67%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 500
    grid consists only of lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        visited = [[False for _ in range(n)] for _ in range(m)]
        directions = [0, 1, 0, -1, 0]

        def check_available(x, y):
            return 0 <= x < m and 0 <= y < n

        def dfs(x, y):
            q = deque([(x, y, -1, -1)])
            while q:
                cur_x, cur_y, father_x, father_y = q.popleft()
                for i in range(4):
                    next_x, next_y = cur_x + directions[i], cur_y + directions[i + 1]
                    if not check_available(next_x, next_y) or (next_x, next_y) == \
                            (father_x, father_y) or grid[cur_x][cur_y] != \
                            grid[next_x][next_y]:
                        continue
                    if visited[next_x][next_y]:
                        return True
                    visited[next_x][next_y] = True
                    q.append((next_x, next_y, cur_x, cur_y))

            return False

        for i in range(m):
            for j in range(n):
                if visited[i][j]:
                    continue
                visited[i][j] = True
                if dfs(i, j):
                    return True

        return False


if __name__ == "__main__":
    s = Solution()
