"""
Source: https://rb.gy/r69dp
Date: 2023/8/25
Skill:
Runtime: 238 ms, faster than 5.32%
Memory Usage: 17.14 MB, less than 17.94%
Time complexity:
Space complexity:
Constraints:
    3 <= edges.length <= 1000
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        n, adj_set, in_degree = len(edges), defaultdict(set), defaultdict(int)
        for edge in edges:
            adj_set[edge[0]].add(edge[1])
            in_degree[edge[1]] += 1

        for i in range(n - 1, -1, -1):
            in_degree2, flag = in_degree.copy(), True
            adj_set[edges[i][0]].remove(edges[i][1])
            in_degree2[edges[i][1]] -= 1
            q, visited = deque(), [False for _ in range(n + 1)]
            for j in range(1, n + 1):
                if in_degree2[j] == 0:
                    q.append(j)
                    visited[j] = True

            if len(q) != 1:
                adj_set[edges[i][0]].add(edges[i][1])
                continue

            while q:
                cur = q.popleft()
                for adj in adj_set[cur]:
                    if not visited[adj]:
                        in_degree2[adj] -= 1
                        if in_degree2[adj] == 0:
                            visited[adj] = True
                            q.append(adj)

            adj_set[edges[i][0]].add(edges[i][1])
            for j in range(1, n + 1):
                if not visited[j]:
                    flag = False
                    break
            if flag:
                return edges[i]


if __name__ == "__main__":
    s = Solution()
