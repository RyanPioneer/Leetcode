"""
Source: https://leetcode.com/problems/shortest-path-with-alternating-colors/
Date: 2023/2/11
Skill:
Runtime: 87 ms, faster than 81.52%
Memory Usage: 14.3 MB, less than 9.9%
Time complexity:
Space complexity:
Constraints:
    There could be self-edges and parallel edges.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        res, red_graph, blue_graph = [-1 for _ in range(n)], defaultdict(list), defaultdict(list)
        visited = [[0, 0] for _ in range(n)]
        q, visited[0] = deque([(0, "red", 0), (0, "blue", 0)]), [1, 1]
        color2graph, color2visited, next_color = {}, {}, {}
        color2graph["red"], color2graph["blue"] = red_graph, blue_graph
        color2visited["red"], color2visited["blue"] = 0, 1
        next_color["red"], next_color["blue"] = "blue", "red"
        for edge in redEdges:
            red_graph[edge[0]].append(edge[1])
        for edge in blueEdges:
            blue_graph[edge[0]].append(edge[1])

        while q:
            cur_node, color, dis = q.popleft()
            if res[cur_node] > dis or res[cur_node] == -1: res[cur_node] = dis
            for neighbor in color2graph[color][cur_node]:
                if not visited[neighbor][color2visited[color]]:
                    q.append((neighbor, next_color[color], dis+1))
                    visited[neighbor][color2visited[color]] = 1

        return res




if __name__ == "__main__":
    s = Solution