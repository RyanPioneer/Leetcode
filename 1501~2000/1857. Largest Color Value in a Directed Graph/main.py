"""
Source: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
Date: 2023/4/9
Skill:
Ref:
Runtime: 2859 ms, faster than 38.10%
Memory Usage: 80.8 MB, less than 89.29%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        sz, in_degree, res = len(colors), [0 for _ in range(len(colors))], 0
        neighbors, q, num = [[] for _ in range(sz)], deque(), 0
        node_color = [[0 for _ in range(26)] for _ in range(sz)]
        for edge in edges:
            in_degree[edge[1]] += 1
            neighbors[edge[0]].append(edge[1])

        for i in range(sz):
            if in_degree[i] == 0:
                q.append(i)
                node_color[i][ord(colors[i]) - ord("a")] = 1

        def merge_color(i, j):  # i merge to j
            for k in range(26):
                node_color[j][k] = max(node_color[i][k], node_color[j][k])

        while q:
            cur_node = q.pop()
            num += 1
            res = max(res, max(node_color[cur_node]))
            for neighbor in neighbors[cur_node]:
                neighbor_color = ord(colors[neighbor]) - ord("a")
                node_color[cur_node][neighbor_color] += 1
                merge_color(cur_node, neighbor)
                node_color[cur_node][neighbor_color] -= 1
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    q.append(neighbor)

        return res if num == sz else -1


if __name__ == "__main__":
    s = Solution()
    colors = "abaca"
    edges = [[0, 1], [0, 2], [2, 3], [3, 4]]
    res = s.largestPathValue(colors, edges)
