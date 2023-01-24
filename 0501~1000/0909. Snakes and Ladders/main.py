"""
Source: https://leetcode.com/problems/snakes-and-ladders/
Date: 2023/1/24
Skill: BFS
Runtime: 129 ms, faster than 66.32%
Memory Usage: 13.9 MB, less than 67.56%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List
from collections import deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools

from collections import deque

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        sz, order = len(board), 1
        columns = [i for i in range(sz)]
        cells = [None for _ in range(sz*sz+1)]
        for i in range(sz-1, -1, -1):
            for column in columns:
                cells[order] = (i, column)
                order += 1
            columns.reverse()

        dist, q = [-1 for _ in range(sz*sz+1)], deque([1])
        dist[1] = 0

        while q:
            cur = q.popleft()
            for i in range(cur+1, min(cur+6, sz*sz)+1):
                x, y = cells[i]
                next = (board[x][y] if board[x][y] != -1 else i)
                if dist[next] == -1:
                    dist[next] = dist[cur]+1
                    q.append(next)

        return dist[sz*sz]