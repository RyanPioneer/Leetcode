"""
Source: https://rb.gy/th6jk
Date: 2023/8/21
Skill:
Ref:
Runtime: 1519 ms, faster than 73.85%
Memory Usage: 72.89 MB, less than 93.08%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 10 ** 5
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
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        adj_list, degree, n = [set() for _ in range(len(amount))], [0 for _ in range(len(amount))], len(amount)
        for edge in edges:
            adj_list[edge[0]].add(edge[1])
            adj_list[edge[1]].add(edge[0])
            degree[edge[0]] += 1
            degree[edge[1]] += 1

        dist, q, res = [-1 for _ in range(n)], deque([0]), -sys.maxsize
        dist[0] = 0
        while q:
            pos = q.popleft()
            for adj in adj_list[pos]:
                if dist[adj] == -1:
                    dist[adj] = dist[pos] + 1
                    q.append(adj)

        bob_pos, dis = defaultdict(int), 0
        bob_pos[bob] = dis
        while bob != 0:
            for adj in adj_list[bob]:
                if dist[adj] < dist[bob]:
                    bob = adj
                    dis += 1
                    bob_pos[bob] = dis
                    break

        q = deque([[0, 0]])
        while q:
            pos, income = q.popleft()
            if pos not in bob_pos or dist[pos] < bob_pos[pos]:
                income += amount[pos]
            elif dist[pos] == bob_pos[pos]:
                income += amount[pos] // 2
            if pos != 0 and degree[pos] == 1:
                res = max(res, income)
            for adj in adj_list[pos]:
                if dist[pos] < dist[adj]:
                    q.append([adj, income])

        return res


if __name__ == "__main__":
    s = Solution()
    edges, bob, amount = [[0, 1], [1, 2], [2, 3]], 3, [-5644, -6018, 1188, -8502]
    res = s.mostProfitablePath(edges, bob, amount)
    print(res)
