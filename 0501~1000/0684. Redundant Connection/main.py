"""
Source: https://rb.gy/1ue98
Date: 2023/8/26
Skill:
Runtime: 66 ms, faster than 56.43%
Memory Usage: 16.99 MB, less than 34.52%
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
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        father, n = [i for i in range(len(edges) + 1)], len(edges)

        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            x_father, y_father = find_father(x), find_father(y)
            if x_father != y_father:
                father[x_father] = y_father

        for edge in edges:
            if find_father(edge[0]) != find_father(edge[1]):
                union(edge[0], edge[1])
            else:
                return edge


if __name__ == "__main__":
    s = Solution()
