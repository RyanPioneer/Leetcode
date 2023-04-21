"""
Source: https://leetcode.com/problems/detect-cycles-in-2d-grid/
Date: 2023/4/21
Skill:
Ref:
Runtime: 2457 ms, faster than 43.75%
Memory Usage: 38.8 MB, less than 91.25%
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
            visited_cells, q = {(x, y)}, deque([(x, y, -1, -1)])
            while q:
                cur_x, cur_y, father_x, father_y = q.popleft()
                visited[cur_x][cur_y] = True
                for i in range(4):
                    next_x, next_y = cur_x + directions[i], cur_y + directions[i + 1]
                    if not check_available(next_x, next_y) or (next_x, next_y) == \
                            (father_x, father_y) or grid[cur_x][cur_y] != \
                            grid[next_x][next_y]:
                        continue
                    if (next_x, next_y) in visited_cells:
                        return True
                    visited_cells.add((next_x, next_y))
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
