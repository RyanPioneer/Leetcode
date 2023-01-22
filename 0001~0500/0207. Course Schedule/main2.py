"""
Source: https://leetcode.com/problems/course-schedule/
Date: 2023/1/22
Skill: BFS
Runtime: 103 ms, faster than 74.19%
Memory Usage: 15.5 MB, less than 87.14%
Time complexity:
Space complexity:
Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
"""

from typing import List
from collections import defaultdict, deque
from functools import lru_cache, cache

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph, q = defaultdict(list), deque()
        in_degree, num = [0 for _ in range(numCourses)], 0
        for prerequisite in prerequisites:
            graph[prerequisite[0]].append(prerequisite[1])
            in_degree[prerequisite[1]] += 1

        for i in range(numCourses):
            if in_degree[i] == 0:
                q.append(i)

        while q:
            node = q.popleft()
            num += 1
            for neighbor in graph[node]:
                in_degree[neighbor] -= 1
                if not in_degree[neighbor]:
                    q.append(neighbor)

        return num == numCourses