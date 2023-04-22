"""
Source: https://leetcode.com/problems/design-graph-with-shortest-path-calculator/
Date: 2023/4/22
Skill: Floyd–Warshall algorithm
Ref:
Runtime: 7271 ms, faster than 6.20%
Memory Usage: 17.1 MB, less than 76.27%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 100
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.dp, self.n = [[math.inf for _ in range(n)] for _ in range(n)], n
        for i in range(n):
            self.dp[i][i] = 0
        for edge in edges:
            self.dp[edge[0]][edge[1]] = edge[2]

        for i in range(n):
            for j in range(n):
                for k in range(n):
                    self.dp[j][k] = min(self.dp[j][k], self.dp[j][i] + self.dp[i][k])

    def addEdge(self, edge: List[int]) -> None:
        if edge[2] < self.dp[edge[0]][edge[1]]:
            self.dp[edge[0]][edge[1]] = edge[2]
            for i in range(self.n):
                for j in range(self.n):
                    self.dp[i][j] = min(self.dp[i][j], self.dp[i][edge[0]] + edge[2] + self.dp[edge[1]][j])

    def shortestPath(self, node1: int, node2: int) -> int:
        return self.dp[node1][node2] if self.dp[node1][node2] < math.inf else -1


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)


if __name__ == "__main__":
    s = Graph()
