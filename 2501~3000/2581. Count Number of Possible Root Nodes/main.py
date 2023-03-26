"""
Source: https://leetcode.com/problems/count-number-of-possible-root-nodes/
Date: 2023/3/27
Skill: 
Runtime: 2007 ms, faster than 97.5%
Memory Usage: 87.2 MB, less than 95.41%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def rootCount(self, edges: List[List[int]], guesses: List[List[int]], k: int) -> int:
        graph, visited, myset, res = [set() for _ in range(len(edges) + 1)], \
            [0 for _ in range(len(edges) + 1)], set(), 0
        for edge in edges:
            graph[edge[0]].add(edge[1])
            graph[edge[1]].add(edge[0])
        for guess in guesses:
            myset.add((guess[0], guess[1]))

        num, q, visited[0] = 0, deque([0]), 1
        while q:
            cur = q.pop()
            for neighbor in graph[cur]:
                if not visited[neighbor]:
                    if (cur, neighbor) in myset:
                        num += 1
                    visited[neighbor] = 1
                    q.append(neighbor)

        visited = [-1 for _ in range(len(edges) + 1)]
        visited[0], q = num, deque([0])
        while q:
            cur = q.pop()
            for neighbor in graph[cur]:
                num = visited[cur]
                if visited[neighbor] == -1:
                    if (cur, neighbor) in myset:
                        num -= 1
                    if (neighbor, cur) in myset:
                        num += 1
                    visited[neighbor] = num
                    q.append(neighbor)

        for number in visited:
            if number >= k:
                res += 1

        return res


if __name__ == "__main__":
    s = Solution()
    edges = [[0, 1], [1, 2], [1, 3], [4, 2]]
    guesses = [[1, 3], [0, 1], [1, 0], [2, 4]]
    k = 3
    res = s.rootCount(edges, guesses, k)
