"""
Source: https://leetcode.com/problems/minesweeper/
Date: 2023/4/11
Skill:
Ref:
Runtime: 182 ms, faster than 67.56%
Memory Usage: 14 MB, less than 97.47%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 50
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        m, n = len(board), len(board[0])
        if board[click[0]][click[1]] == "M":
            board[click[0]][click[1]] = "X"
            return board

        def check_available(x, y):
            return 0 <= x < m and 0 <= y < n

        directions = [[0, 1], [0, -1], [-1, 0], [1, 0], [1, 1], [-1, -1], [1, -1], [-1, 1]]
        visited = [[0 for _ in range(n)] for _ in range(m)]
        q = deque([(click[0], click[1])])
        while q:
            cur_x, cur_y = q.popleft()
            unvisited_neighbors, bomb_count = [], 0
            for d in directions:
                next_x, next_y = cur_x + d[0], cur_y + d[1]
                if not check_available(next_x, next_y):
                    continue
                if board[next_x][next_y] == "M":
                    bomb_count += 1
                else:
                    if visited[next_x][next_y] == 0:
                        unvisited_neighbors.append((next_x, next_y))

            if bomb_count == 0:
                board[cur_x][cur_y] = "B"
                for neighbor in unvisited_neighbors:
                    q.append((neighbor[0], neighbor[1]))
                    visited[neighbor[0]][neighbor[1]] = 1
            else:
                board[cur_x][cur_y] = chr(ord("0") + bomb_count)

        return board


if __name__ == "__main__":
    s = Solution()
