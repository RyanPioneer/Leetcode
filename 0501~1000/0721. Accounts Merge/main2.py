"""
Source: https://leetcode.com/problems/accounts-merge/
Date: 2023/1/25
Skill: DFS
Runtime: 218 ms, faster than 67.13%
Memory Usage: 27.6 MB, less than 7.92%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools

class Solution:
    def accountsMerge(self, accounts):
        graph, names = defaultdict(set), defaultdict()
        for acc in accounts:
            name = acc[0]
            email0 = acc[1]
            for email in acc[1:]:
                graph[email].add(email0)
                graph[email0].add(email)
                names[email] = name

        res, visited, label = defaultdict(list), set(), 0

        def dfs(node):
            visited.add(node)
            res[label].append(node)
            for neighbor in graph[node]:
                if neighbor not in visited:
                    dfs(neighbor)


        for email in graph:
            if email not in visited:
                dfs(email)
                label += 1


        return [[names[val[0]]] + sorted(val) for _, val in res.items()]