"""
Source: https://leetcode.com/problems/cheapest-flights-within-k-stops/
Date: 2023/1/26
Skill: BFS
Runtime: 106 ms, faster than 88.35%
Memory Usage: 15 MB, less than 89.11%
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
        graph, dis = defaultdict(list), [-1 for _ in range(n)]
        for f, to, price in flights:
            graph[f].append([to, price])

        dis[src], q, step = 0, deque([src]), 0

        while q and step <= k:
            sz = len(q)
            new_dis = list(dis)
            for _ in range(sz):
                cur = q.popleft()
                for neighbor in graph[cur]:
                    if new_dis[neighbor[0]] == -1 or new_dis[neighbor[0]] > dis[cur]+neighbor[1]:
                        new_dis[neighbor[0]] = dis[cur] + neighbor[1]
                        q.append(neighbor[0])
            step += 1
            dis = new_dis

        return dis[dst]

if __name__ == "__main__":
    s = Solution
    flights = [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
    res = s.findCheapestPrice(s, 4, flights, 0, 3, 1)