"""
Source: https://leetcode.com/problems/01-matrix/description/
Date: 2023/1/23
Skill: BFS on zero cells first
Runtime: 650 ms, faster than 79.17%
Memory Usage: 17 MB, less than 67.50%
Time complexity:
Space complexity:
Constraints:

"""
import math
from typing import List
from collections import defaultdict, deque
from functools import lru_cache, cache

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n, q = len(mat), len(mat[0]), deque()
        dir = [0, 1, 0, -1, 0]
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    mat[i][j] = -1
                else:
                    q.append((i, j))

        while q:
            x, y = q.popleft()
            for i in range(4):
                nx, ny = x + dir[i], y + dir[i + 1]
                if nx < 0 or nx >= m or ny < 0 or ny >= n or mat[nx][ny] != -1: continue
                mat[nx][ny] = mat[x][y] + 1
                q.append((nx, ny))

        return mat