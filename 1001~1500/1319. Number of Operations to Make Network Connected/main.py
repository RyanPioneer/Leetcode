"""
Source: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
Date: 2023/3/24
Skill: DFS
Runtime: 492 ms, faster than 84.42%
Memory Usage: 38.7 MB, less than 42.87%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        edges, visited = [set() for _ in range(n)], [0 for _ in range(n)]
        component_num, self.cycle_num = 0, 0
        for connection in connections:
            edges[connection[0]].add(connection[1])
            edges[connection[1]].add(connection[0])

        def dfs(cur):
            for neighbor in edges[cur]:
                if visited[neighbor]:
                    self.cycle_num += 1
                else:
                    visited[neighbor] = 1
                    edges[neighbor].remove(cur)
                    dfs(neighbor)

        for i in range(n):
            if not visited[i]:
                visited[i] = 1
                component_num += 1
                dfs(i)

        self.cycle_num //= 2
        return component_num - 1 if self.cycle_num >= component_num - 1 else -1


if __name__ == "__main__":
    s = Solution()
    n = 6
    connections = [[0, 1], [0, 2], [0, 3], [1, 2]]
    res = s.makeConnected(n, connections)
