"""
Source: https://leetcode.com/problems/last-day-where-you-can-still-cross/
Date: 2023/3/11
Skill: Union Find
Runtime: 2104 ms, faster than 72.4%
Memory Usage: 24.2 MB, less than 39.78%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        father = [i for i in range(row * col)]
        direction = [0, 1, 0, -1, 0]

        def findFather(a):
            if father[a] != a:
                father[a] = findFather(father[a])
            return father[a]

        def union(a, b):
            x, y = father[a], father[b]
            if x < y:
                father[y] = x
            else:
                father[x] = y

        def check_valid(x, y):
            return x >= 0 and x < row and y >= 0 and y < col

        mat = [[0 for _ in range(col)] for _ in range(row)]
        for cell in cells:
            mat[cell[0] - 1][cell[1] - 1] = 1

        for i in range(row):
            for j in range(col):
                if mat[i][j] == 0:
                    for k in range(4):
                        if check_valid(i + direction[k], j + direction[k + 1]) \
                                and mat[i + direction[k]][j + direction[k + 1]] == 0:
                            if findFather(i * col + j) != findFather((i + direction[k]) * col + j \
                                    + direction[k + 1]):
                                union(i * col + j, (i + direction[k]) * col + j + direction[k + 1])

        for i in range(col-1):
            if findFather(i) != findFather(i+1):
                union(i, i+1)
            if findFather(col * (row - 1) + i) != findFather(col * (row - 1) + i + 1):
                union(col * (row - 1) + i, col * (row - 1) + i + 1)

        for h in range(len(cells)-1, -1, -1):
            if findFather(0) == findFather(row * col - 1):
                return h+1
            i, j = cells[h][0]-1, cells[h][1]-1
            mat[i][j] = 0
            for k in range(4):
                if check_valid(i + direction[k], j + direction[k + 1]) \
                        and mat[i + direction[k]][j + direction[k + 1]] == 0:
                    if findFather(i * col + j) != findFather((i + direction[k]) * col + j \
                                                             + direction[k + 1]):
                        union(i * col + j, (i + direction[k]) * col + j + direction[k + 1])

        return 0


if __name__ == "__main__":
    s = Solution()
