"""
Source: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
Date: 2022/12/30
Skill: 
Runtime: 355 ms, faster than 70.66%
Memory Usage: 22.6 MB, less than 15.38%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= n <= 200
"""

from typing import List
import heapq

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        MOD = pow(10, 9)+7
        adj, count = [[] for _ in range(n)], [-1 for _ in range(n)]
        for s, t, w in roads:
            adj[s].append((t, w))
            adj[t].append((s, w))
        h, dist = [(0, 0)], [-1 for _ in range(n)]
        heapq.heapify(h)
        while h:
            dis, node = heapq. heappop(h)
            if dist[node] != -1:
                continue
            dist[node] = dis
            for neighbor in adj[node]:
                if dist[neighbor[0]] == -1:
                    heapq.heappush(h, (dis+neighbor[1], neighbor[0]))

        def dfs(cur_node, cur_dist):
            if dist[cur_node] != cur_dist: return 0
            if cur_node == 0: return 1
            if count[cur_node] != -1: return count[cur_node]
            num = 0
            for neighbor in adj[cur_node]:
                num += dfs(neighbor[0], cur_dist-neighbor[1])

            count[cur_node] = num
            return num

        return dfs(n-1, dist[n-1])%MOD