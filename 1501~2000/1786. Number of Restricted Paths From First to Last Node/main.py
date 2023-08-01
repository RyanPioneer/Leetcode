"""
Source: https://rb.gy/0urwk
Date: 2023/8/1
Skill:
Ref:
Runtime: 1832 ms, faster than 93.43%
Memory Usage: 81.4 MB, less than 13.14%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        MOD, dist, memo = 10 ** 9 + 7, [-1 for _ in range(n)], [-1 for _ in range(n)]
        adj_list = [[] for _ in range(n)]
        for edge in edges:
            adj_list[edge[0] - 1].append([edge[1] - 1, edge[2]])
            adj_list[edge[1] - 1].append([edge[0] - 1, edge[2]])
        heap = [[0, n - 1]]
        heapify(heap)
        while heap:
            [dis, node] = heappop(heap)
            if dist[node] != -1:
                continue
            dist[node] = dis
            for [neighbor, weight] in adj_list[node]:
                if dist[neighbor] != -1:
                    continue
                heappush(heap, [dis + weight, neighbor])

        def dfs(cur_node):
            if cur_node == n - 1:
                return 1
            if memo[cur_node] != -1:
                return memo[cur_node]
            cnt = 0
            for [neighbor, weight] in adj_list[cur_node]:
                if dist[neighbor] < dist[cur_node]:
                    cnt += dfs(neighbor)
            memo[cur_node] = cnt
            return cnt

        return dfs(0) % MOD


if __name__ == "__main__":
    s = Solution()
    n, edges = 5, [[1, 2, 3], [1, 3, 3], [2, 3, 1], [1, 4, 2], [5, 2, 2], [3, 5, 1], [5, 4, 10]]
    res = s.countRestrictedPaths(n, edges)
