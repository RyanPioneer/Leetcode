"""
Source: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
Date: 2023/1/25
Skill: BFS
Runtime: 1256 ms, faster than 81.3%
Memory Usage: 31.9 MB, less than 71.26%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List
from collections import deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools

class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        if node1 == node2: return node1
        q1, q2, dist, res = deque([node1]), deque([node2]), [[-1, -1] for _ in range(len(edges))], []
        dist[node1], dist[node2] = [1, 0], [2, 0]
        while q1 or q2:
            find = False
            if q1:
                sz = len(q1)
                for _ in range(sz):
                    cur = q1.popleft()
                    if edges[cur] != -1 and dist[edges[cur]][0] == -1:
                        dist[edges[cur]] = [1, dist[cur][1] + 1]
                        q1.append(edges[cur])
                    elif edges[cur] != -1 and dist[edges[cur]][0] == 2:
                        find = True
                        res.append(edges[cur])

            if q2:
                sz = len(q2)
                for _ in range(sz):
                    cur = q2.popleft()
                    if edges[cur] != -1 and dist[edges[cur]][0] == -1:
                        dist[edges[cur]] = [2, dist[cur][1] + 1]
                        q2.append(edges[cur])
                    elif edges[cur] != -1 and dist[edges[cur]][0] == 1:
                        find = True
                        res.append(edges[cur])

            if find: break

        if len(res) == 0: return -1
        return min(res)