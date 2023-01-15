"""
Source: https://leetcode.com/problems/number-of-good-paths/
Date: 2023/1/15
Skill: Union-Find
Ref:
Runtime: 2361 ms, faster than 80.37%
Memory Usage: 34.8 MB, less than 71.46%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

# Definition for a binary tree node.
class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        sz, max_num, res = len(vals), max(vals), len(vals)
        parent = [i for i in range(sz)]

        def find_father(n):
            if parent[n] == n: return n
            parent[n] = find_father(parent[n])
            return parent[n]
        def union(n1, n2):
            parent1, parent2 = find_father(n1), find_father(n2)
            if vals[parent1] < vals[parent2]:
                parent[parent2] = parent1
            else:
                parent[parent1] = parent2

        e, nodes = [[] for _ in range(max_num+1)], [set() for _ in range(max_num+1)]
        for edge in edges:
            n1, n2 = edge[0], edge[1]
            nodes[vals[n1]].add(n1)
            nodes[vals[n2]].add(n2)
            if vals[n1] < vals[n2]:
                n1, n2 = n2, n1
            e[vals[n1]].append((n1, n2))

        for i in range(min(vals), max_num+1):
            for n1, n2 in e[i]:
                if find_father(n1) != find_father(n2):
                    union(n1, n2)

            my_dict = defaultdict(int)
            for idx in nodes[i]:
                my_dict[find_father(idx)] += 1

            for key, value in my_dict.items():
                res += value * (value-1) // 2

        return res