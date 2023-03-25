"""
Source: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
Date: 2023/3/25
Skill:
Runtime: 2619 ms, faster than 13.88%
Memory Usage: 119.1 MB, less than 5.34%
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
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        graph, visited = [set() for _ in range(n)], [False for _ in range(n)]
        groups, group_id, res = [], 0, 0
        for edge in edges:
            graph[edge[0]].add(edge[1])
            graph[edge[1]].add(edge[0])

        def dfs(idx):
            for neighbor in graph[idx]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    groups[group_id].add(neighbor)
                    dfs(neighbor)

        for i in range(n):
            if not visited[i]:
                groups.append(set([i]))
                dfs(i)
                group_id += 1

        for i in range(group_id - 1):
            num = len(groups[i])
            n -= num
            res += num * n

        return res


if __name__ == "__main__":
    s = Solution()
    n = 7
    edges = [[0, 2], [0, 5], [2, 4], [1, 6], [5, 4]]
    res = s.countPairs(n, edges)
