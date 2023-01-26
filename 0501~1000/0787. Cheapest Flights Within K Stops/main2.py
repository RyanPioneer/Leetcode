"""
Source: https://leetcode.com/problems/cheapest-flights-within-k-stops/
Date: 2023/1/26
Skill: Bellman Ford
Runtime: 187 ms, faster than 58.88%
Memory Usage: 15.1 MB, less than 73.37%
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
        dis = [-1 for _ in range(n)]
        dis[src] = 0
        for _ in range(k+1):
            new_dis = list(dis)
            for fro, to, price in flights:
                if dis[fro] != -1 and (new_dis[to] == -1 or dis[fro] + price < new_dis[to]):
                    new_dis[to] = dis[fro] + price
            dis = new_dis
        return dis[dst]