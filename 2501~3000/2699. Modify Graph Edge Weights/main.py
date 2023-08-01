"""
Source: https://rb.gy/u2qc4
Date: 2023/7/31
Skill:
Ref:
Runtime: 2712 ms, faster than 75.21%
Memory Usage: 20.27 MB, less than 47.93%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[
        List[int]]:
        neighbors, todo = [defaultdict(int) for _ in range(n)], defaultdict(int)
        for edge in edges:
            node1, node2, weight = edge[0], edge[1], edge[2]
            if weight == -1:
                todo[(node1, node2)] = todo[(node2, node1)] = 1
                weight = 1
            neighbors[node1][node2] = weight
            neighbors[node2][node1] = weight

        dist1, dist = [-1 for _ in range(n)], [-1 for _ in range(n)]
        heap1, heap = [(0, destination)], [(0, source)]
        heapify(heap1)
        heapify(heap)

        while heap1:
            dis, node = heappop(heap1)
            if dist1[node] != -1:
                continue
            dist1[node] = dis
            for key in neighbors[node].keys():
                next_node, weight = key, neighbors[node][key]
                if dist1[next_node] != -1:
                    continue
                heappush(heap1, (dis + weight, next_node))

        while heap:
            dis, node = heappop(heap)
            if dist[node] != -1:
                continue
            dist[node] = dis
            if node == destination and dis != target:
                return []
            for key in neighbors[node].keys():
                next_node, weight = key, neighbors[node][key]
                if todo[(node, next_node)] == 1 and dis + dist1[next_node] + weight < target:
                    neighbors[node][next_node] = neighbors[next_node][node] = target - (dis + dist1[next_node])
                if dist[next_node] == -1:
                    heappush(heap, (dis + neighbors[node][next_node], next_node))

        for edge in edges:
            node1, node2, weight = edge[0], edge[1], edge[2]
            if (node1, node2) in todo:
                edge[2] = neighbors[node1][node2]
        return edges


if __name__ == "__main__":
    s = Solution()
    n, edges, source, destination, taregt = 3, [[0, 1, -1], [0, 2, 5]], 0, 2, 6
    res = s.modifiedGraphEdges(n, edges, source, destination, taregt)
