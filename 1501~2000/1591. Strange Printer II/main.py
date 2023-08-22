"""
Source: https://rb.gy/yi4bl
Date: 2023/8/22
Skill:
Ref:
Runtime: 1165 ms, faster than 6.85%
Memory Usage: 18.21 MB, less than 5.48%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 60
    1 <= targetGrid[row][col] <= 60
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right
from functools import cache


class Solution:
    def isPrintable(self, targetGrid: List[List[int]]) -> bool:
        m, n, visited = len(targetGrid), len(targetGrid[0]), [False for _ in range(61)]
        pos = [[m - 1, 0, n - 1, 0] for _ in range(61)]  # up, down, left, right
        next, indegree = defaultdict(list), defaultdict(int)
        for i in range(m):
            for j in range(n):
                visited[targetGrid[i][j]] = True
                pos[targetGrid[i][j]][0] = min(pos[targetGrid[i][j]][0], i)
                pos[targetGrid[i][j]][1] = max(pos[targetGrid[i][j]][1], i)
                pos[targetGrid[i][j]][2] = min(pos[targetGrid[i][j]][2], j)
                pos[targetGrid[i][j]][3] = max(pos[targetGrid[i][j]][3], j)

        for i in range(m):
            for j in range(n):
                for k in range(61):
                    if pos[k][0] <= i <= pos[k][1] and pos[k][2] <= j <= pos[k][3] and targetGrid[i][j] != k:
                        indegree[targetGrid[i][j]] += 1
                        next[k].append(targetGrid[i][j])

        q = deque()
        for i in range(61):
            if visited[i] and indegree[i] == 0:
                q.append(i)
        while q:
            cur = q.popleft()
            visited[cur] = False
            for adj in next[cur]:
                indegree[adj] -= 1
                if indegree[adj] == 0:
                    q.append(adj)

        for i in range(61):
            if visited[i]:
                return False
        return True


if __name__ == "__main__":
    s = Solution()
    targetGrid = [[6, 2, 2, 5], [2, 2, 2, 5], [2, 2, 2, 5], [4, 3, 3, 4]]
    res = s.isPrintable(targetGrid)
    print(res)
