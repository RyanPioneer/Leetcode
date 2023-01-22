"""
Source: https://leetcode.com/problems/course-schedule/
Date: 2023/1/22
Skill: DFS
Runtime: 105 ms, faster than 67.88%
Memory Usage: 17 MB, less than 38.51%
Time complexity:
Space complexity:
Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
"""

from typing import List
from collections import defaultdict
from functools import lru_cache, cache

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        visited = [0 for _ in range(numCourses)]
        for prerequisite in prerequisites:
            graph[prerequisite[0]].append(prerequisite[1])

        def dfs(root):
            if visited[root] == 1: return True
            elif visited[root] == 2: return False
            visited[root] = 2
            for neighbor in graph[root]:
                if visited[neighbor] == 1: continue
                elif visited[neighbor] == 2: return False
                if not dfs(neighbor): return False

            visited[root] = 1
            return True

        for i in range(numCourses):
            if visited[i] == 1: continue
            elif not dfs(i): return False

        return True