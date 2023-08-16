"""
Source: https://rb.gy/rddxg
Date: 2023/8/16
Skill:
Ref:
Runtime: 141 ms, faster than 79.79%
Memory Usage: 17.49 MB, less than 99.32%
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
    def solve(self, board: List[List[str]]) -> None:
        m, n, dirs = len(board), len(board[0]), [0, 1, 0, -1, 0]

        def check_feasible(x, y):
            return 0 <= x < m and 0 <= y < n

        def bfs(x, y):
            q = deque()
            board[x][y] = "S"
            q.append([x, y])
            while q:
                a, b = q.popleft()
                for i in range(4):
                    next_x, next_y = a + dirs[i], b + dirs[i + 1]
                    if check_feasible(next_x, next_y) and board[next_x][next_y] == "O":
                        board[next_x][next_y] = "S"
                        q.append([next_x, next_y])

        for i in range(m):
            if board[i][0] == "O":
                bfs(i, 0)
            if board[i][-1] == "O":
                bfs(i, n - 1)

        for i in range(n):
            if board[0][i] == "O":
                bfs(0, i)
            if board[-1][i] == "O":
                bfs(m - 1, i)

        for i in range(m):
            for j in range(n):
                if board[i][j] == "S":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"


if __name__ == "__main__":
    s = Solution()
