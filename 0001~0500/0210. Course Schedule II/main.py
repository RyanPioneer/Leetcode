"""
Source: https://leetcode.com/problems/course-schedule-ii/
Date: 2023/1/31
Skill:
Runtime: 95 ms, faster than 95.86%
Memory Usage: 15.5 MB, less than 84.89%
Time complexity:
Space complexity:
Constraints:
    1 <= numCourses <= 2000
"""

import math
from typing import List
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph, in_degree = defaultdict(list), [0 for _ in range(numCourses)]
        for prerequisite in prerequisites:
            graph[prerequisite[1]].append(prerequisite[0])
            in_degree[prerequisite[0]] += 1

        finished, q, res = 0, deque(), []
        for i in range(numCourses):
            if in_degree[i] == 0:
                q.append(i)

        while q:
            cur = q.popleft()
            res.append(cur)
            finished += 1
            for neighbor in graph[cur]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    q.append(neighbor)

        if finished == numCourses: return res
        else: return []