"""
Source: https://leetcode.com/problems/bus-routes/
Date: 2023/3/15
Skill:
Runtime: 420 ms, faster than 88.43%
Memory Usage: 45.7 MB, less than 44.32%
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
        stop2route, visited_route = defaultdict(set), defaultdict(int)
        for i in range(len(routes)):
            for stop in routes[i]:
                stop2route[stop].add(i)

        while q:
            step += 1
            sz = len(q)
            for _ in range(sz):
                cur_stop = q.popleft()
                for route in stop2route[cur_stop]:
                    if not visited_route[route]:
                        visited_route[route] = 1
                        for next_stop in routes[route]:
                            if target == next_stop:
                                return step + 1
                            q.append(next_stop)

        return -1


if __name__ == "__main__":
    s = Solution()
