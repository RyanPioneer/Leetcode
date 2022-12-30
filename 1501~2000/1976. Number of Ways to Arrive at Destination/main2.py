"""
Source: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
Date: 2022/12/30
Skill:
Runtime: 319 ms, faster than 95.16%
Memory Usage: 20.3 MB, less than 86.32%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 200
"""

from typing import List
import heapq
import math

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        MOD = pow(10, 9)+7
        adj, dist, cnt = [[] for _ in range(n)], [math.inf for _ in range(n)], [0 for _ in range(n)]
        for s, t, w in roads:
            adj[s].append((t, w))
            adj[t].append((s, w))
        h = [(0, 0)]
        cnt[0] = 1
        dist[0] = 0
        heapq.heapify(h)
        while h:
            dis, node = heapq. heappop(h)
            if dist[node] < dis:
                continue
            for neighbor in adj[node]:
                if dist[neighbor[0]] == dis + neighbor[1]:
                    cnt[neighbor[0]] += cnt[node]
                    #heapq.heappush(h, (dis+neighbor[1], neighbor[0]))
                elif dist[neighbor[0]] > dis + neighbor[1]:
                    dist[neighbor[0]] = dis + neighbor[1]
                    cnt[neighbor[0]] = cnt[node]
                    heapq.heappush(h, (dis + neighbor[1], neighbor[0]))

        return cnt[n-1]%MOD