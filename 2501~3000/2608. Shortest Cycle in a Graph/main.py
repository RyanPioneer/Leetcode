"""
Source: https://leetcode.com/problems/shortest-cycle-in-a-graph/
Date: 2023/4/22
Skill:
Ref:
Runtime: 1747 ms, faster than 70.26%
Memory Usage: 14.5 MB, less than 66.99%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        graph, res = [set() for _ in range(n)], math.inf
        for edge in edges:
            graph[edge[0]].add(edge[1])
            graph[edge[1]].add(edge[0])

        def bfs(start, end):
            visited, q = [False for _ in range(n)], deque([(start, 0)])
            visited[start] = True
            while q:
                cur_node, dis = q.popleft()
                for neighbor in graph[cur_node]:
                    if neighbor == end:
                        return dis + 1
                    if visited[neighbor]:
                        continue
                    visited[neighbor] = True
                    q.append((neighbor, dis + 1))

            return math.inf

        for edge in edges:
            graph[edge[0]].remove(edge[1])
            res = min(bfs(edge[0], edge[1]) + 1, res)
            graph[edge[0]].add(edge[1])

        return res if res < math.inf else -1


if __name__ == "__main__":
    s = Solution()
