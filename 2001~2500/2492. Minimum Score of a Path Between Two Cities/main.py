"""
Source: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
Date: 2023/2/8
Skill:
Runtime: 1761 ms, faster than 78.46%
Memory Usage: 67.8 MB, less than 67.69%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 10^5
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        graph, visited, res, q = defaultdict(list), set(), math.inf, deque([1])
        for a, b, dis in roads:
            graph[a].append((b, dis))
            graph[b].append((a, dis))

        visited.add(1)
        while q:
            cur = q.popleft()
            for neighbor, distance in graph[cur]:
                res = min(res, distance)
                if neighbor not in visited:
                    visited.add(neighbor)
                    q.append(neighbor)

        return res


if __name__ == "__main__":
    s = Solution