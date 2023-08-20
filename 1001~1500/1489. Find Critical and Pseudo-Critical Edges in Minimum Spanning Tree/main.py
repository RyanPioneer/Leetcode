"""
Source: https://rb.gy/atdwi
Date: 2023/8/19
Skill: Kruskal's Algorithm
Ref:
Runtime: 1341 ms, faster than 35.71%
Memory Usage: 16.46 MB, less than 91.21%
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
from functools import cache


class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        for i in range(len(edges)):
            edges[i].append(i)
        edges.sort(key=lambda x: x[2])
        res, father, sz = [[], []], [i for i in range(n)], len(edges)

        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            x_father, y_father = find_father(x), find_father(y)
            if x_father != y_father:
                father[x_father] = y_father

        def kruskal(deleted_edge):
            total = 0
            for i in range(len(edges)):
                if i == deleted_edge:
                    continue
                if find_father(edges[i][0]) != find_father(edges[i][1]):
                    total += edges[i][2]
                    union(edges[i][0], edges[i][1])
            for i in range(n - 1):
                if find_father(i) != find_father(i + 1):
                    total = sys.maxsize
                    break
            return total

        min_sum, set1 = kruskal(-1), set()
        for i in range(sz):
            for j in range(n):
                father[j] = j
            score = kruskal(i)
            if score > min_sum:
                res[0].append(edges[i][3])
                set1.add(i)
        for i in range(sz):
            if i in set1:
                continue
            for j in range(n):
                father[j] = j
            edges.insert(0, edges[i])
            if kruskal(i + 1) == min_sum:
                res[1].append(edges[i + 1][3])
            edges.pop(0)

        return res


if __name__ == "__main__":
    s = Solution()
    n, edges = 6, [[0, 1, 1], [1, 2, 1], [0, 2, 1], [2, 3, 4], [3, 4, 2], [3, 5, 2], [4, 5, 2]]
    res = s.findCriticalAndPseudoCriticalEdges(n, edges)
