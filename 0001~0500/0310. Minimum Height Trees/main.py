"""
Source: https://leetcode.com/problems/minimum-height-trees/
Date: 2023/1/27
Skill: Topological Sorting
Runtime: 542 ms, faster than 68.83%
Memory Usage: 24.2 MB, less than 93.95%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 2 * 10^4
    The given input is guaranteed to be a tree and there will be no repeated edges.
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1: return [0]
        graph, degree, q = defaultdict(list), [0 for _ in range(n)], deque()
        for node1, node2 in edges:
            graph[node1].append(node2)
            graph[node2].append(node1)
            degree[node1] += 1
            degree[node2] += 1

        for i in range(n):
            if degree[i] == 1:
                q.append(i)

        while q:
            sz, res = len(q), []
            for _ in range(sz):
                cur = q.popleft()
                res.append(cur)
                for neighbor in graph[cur]:
                    degree[neighbor] -= 1
                    if degree[neighbor] == 1:
                        q.append(neighbor)

            if not q: return res