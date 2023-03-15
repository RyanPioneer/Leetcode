"""
Source: https://leetcode.com/problems/bus-routes/
Date: 2023/3/15
Skill:
Runtime: TLE
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    1 <= routes.length <= 500.
    1 <= routes[i].length <= 10^5
"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        step, q = -1, deque([source])
        edges, visited = defaultdict(set), defaultdict(int)
        visited[source] = 1
        for route in routes:
            for i in range(len(route)):
                for j in range(i+1, len(route)):
                    edges[route[i]].add(route[j])
                    edges[route[j]].add(route[i])

        while q:
            step += 1
            sz = len(q)
            for _ in range(sz):
                cur_stop = q.popleft()
                for neighbor in edges[cur_stop]:
                    if not visited[neighbor]:
                        if neighbor == target:
                            return step + 1
                        q.append(neighbor)
                        visited[neighbor] = 1
                        edges[neighbor].remove(cur_stop)

        return -1


if __name__ == "__main__":
    s = Solution()
