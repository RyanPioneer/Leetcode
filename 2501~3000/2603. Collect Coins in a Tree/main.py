"""
Source: https://leetcode.com/problems/collect-coins-in-a-tree/
Date: 2023/4/10
Skill:
Ref:
Runtime: 2557 ms, faster than 11.66%
Memory Usage: 31.2 MB, less than 55.97%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def collectTheCoins(self, coins: List[int], edges: List[List[int]]) -> int:
        res, sz, q = 0, len(coins), deque()
        node_depth, graph = [0 for _ in range(sz)], [set() for _ in range(sz)]
        degree = [0 for _ in range(sz)]

        for edge in edges:
            degree[edge[0]] += 1
            degree[edge[1]] += 1
            graph[edge[0]].add(edge[1])
            graph[edge[1]].add(edge[0])

        for i in range(sz):
            if degree[i] == 1 and coins[i] == 0:
                degree[i] = 0
                q.append(i)

        while q:
            cur_node = q.popleft()
            for neighbor in graph[cur_node]:
                graph[neighbor].remove(cur_node)
                degree[neighbor] -= 1
                if degree[neighbor] == 1 and coins[neighbor] == 0:
                    degree[neighbor] = 0
                    q.append(neighbor)

        q.clear()
        for i in range(sz):
            if degree[i] == 1:
                q.append(i)

        while q:
            cur_node = q.popleft()
            for neighbor in graph[cur_node]:
                node_depth[neighbor] = max(node_depth[neighbor], node_depth[cur_node] + 1)
                graph[neighbor].remove(cur_node)
                degree[neighbor] -= 1
                if degree[neighbor] == 1:
                    q.append(neighbor)

        for i in range(sz):
            if node_depth[i] >= 2:
                res += 1

        return (res - 1) * 2 if res > 0 else 0


if __name__ == "__main__":
    s = Solution()
    coins = [1, 0, 0, 0, 0, 1]
    edges = [[0, 1], [1, 2], [2, 3], [3, 4], [4, 5]]
    res = s.collectTheCoins(coins, edges)
