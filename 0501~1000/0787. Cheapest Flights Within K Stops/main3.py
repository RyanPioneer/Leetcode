"""
Source: https://leetcode.com/problems/cheapest-flights-within-k-stops/
Date: 2023/1/26
Skill: Dijkstra
Runtime: 110 ms, faster than 81.56%
Memory Usage: 15.5 MB, less than 26.71%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph, steps, heap = defaultdict(list), [math.inf for _ in range(n)], [(0, src, 0)] #* cost, node ID, step
        heapify(heap)
        for fro, to, price in flights:
            graph[fro].append((to, price))

        while heap:
            cost, ID, step = heappop(heap)
            if ID == dst: return cost
            if steps[ID] < step or step == k + 1: continue
            steps[ID] = step
            for to, price in graph[ID]:
                heappush(heap, (cost + price, to, step + 1))

        return -1

if __name__ == "__main__":
    s = Solution
    flights = [[0,1,5],[1,2,5],[0,3,2],[3,1,2],[1,4,1],[4,2,1]]
    n = 5
    res = s.findCheapestPrice(s, n, flights, 0, 2, 2)