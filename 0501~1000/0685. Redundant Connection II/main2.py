"""
Source: https://rb.gy/r69dp
Date: 2023/8/26
Skill:
Runtime: 67 ms, faster than 77.38%
Memory Usage: 16.92 MB, less than 56.39%
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
        n, cand = len(edges), []
        father = [i for i in range(n + 1)]

        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            father_x, father_y = find_father(x), find_father(y)
            if father_x != father_y:
                father[father_x] = father_y

        for edge in edges:
            if father[edge[1]] != edge[1]:
                cand = [[father[edge[1]], edge[1]], [edge[0], edge[1]]]
                break
            else:
                father[edge[1]] = edge[0]

        father = [i for i in range(n + 1)]
        for edge in edges:
            if len(cand) > 0 and edge == cand[1]:
                continue
            if find_father(edge[0]) == find_father(edge[1]):
                if len(cand) == 0:
                    return edge
                else:
                    return cand[0]
            else:
                union(find_father(edge[0]), find_father(edge[1]))

        return cand[1]


if __name__ == "__main__":
    s = Solution()
