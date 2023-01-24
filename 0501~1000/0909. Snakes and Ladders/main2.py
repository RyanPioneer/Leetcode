"""
Source: https://leetcode.com/problems/snakes-and-ladders/
Date: 2023/1/24
Skill: Dijkstra's algorithm
Runtime: 385 ms, faster than 11.57%
Memory Usage: 14 MB, less than 31.20%
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
        sz = len(board)
        cells, label = [None for _ in range(sz*sz+1)], 1
        columns = [i for i in range(sz)]
        for i in range(sz-1, -1, -1):
            for column in columns:
                cells[label] = (i, column)
                label += 1
            columns.reverse()

        heap = [(0, 1)]
        heapify(heap)
        dis = [-1 for _ in range(sz*sz+1)]
        dis[1] = 0
        while heap:
            d, cur = heappop(heap)
            if d != dis[cur]: continue
            for i in range(cur+1, min(cur+6, sz*sz)+1):
                x, y = cells[i]
                next = board[x][y] if board[x][y] != -1 else i
                if dis[next] == -1 or dis[cur] + 1 < dis[next]:
                    dis[next] = dis[cur] + 1
                    heappush(heap, (dis[next], next))

        return dis[sz*sz]