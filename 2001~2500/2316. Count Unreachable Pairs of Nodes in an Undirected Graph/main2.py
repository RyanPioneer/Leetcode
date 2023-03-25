"""
Source: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
Date: 2023/3/25
Skill:
Runtime: 2073 ms, faster than 87.54%
Memory Usage: 75.3 MB, less than 67.26%
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
        father, res = [i for i in range(n)], 0

        def find_father(i):
            if father[i] != i:
                father[i] = find_father(father[i])
            return father[i]

        def union(i, j):
            i_father, j_father = find_father(i), find_father(j)
            if i_father != j_father:
                if i_father > j_father:
                    i_father, j_father = j_father, i_father
                father[j_father] = i_father

        for edge in edges:
            union(edge[0], edge[1])

        cnt = Counter([find_father(i) for i in range(n)])
        for value in cnt:
            n -= cnt[value]
            res += cnt[value] * n

        return res
