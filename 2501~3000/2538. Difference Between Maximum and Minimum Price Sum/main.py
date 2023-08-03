"""
Source: https://rb.gy/l4lho
Date: 2023/8/3
Skill:
Ref:
Runtime: 1833 ms, faster than 95.12%
Memory Usage: 64.29 MB, less than 51.22%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def maxOutput(self, n: int, edges: List[List[int]], price: List[int]) -> int:
        if n == 1:
            return 0
        neighbors, res = [[] for _ in range(n)], 0
        dis_to_leaf, dis_to_non_leaf = [0 for _ in range(n)], [0 for _ in range(n)]
        for edge in edges:
            neighbors[edge[0]].append(edge[1])
            neighbors[edge[1]].append(edge[0])

        def dfs(cur_node, parent):
            if len(neighbors[cur_node]) == 1 and neighbors[cur_node][0] == parent:
                dis_to_leaf[cur_node] = price[cur_node]
                return
            to_leaf, to_nonleaf = 0, 0
            for neighbor in neighbors[cur_node]:
                if neighbor == parent:
                    continue
                dfs(neighbor, cur_node)
                to_leaf, to_nonleaf = max(to_leaf, dis_to_leaf[neighbor]), max(to_nonleaf, dis_to_non_leaf[neighbor])

            dis_to_leaf[cur_node] = to_leaf + price[cur_node]
            dis_to_non_leaf[cur_node] = to_nonleaf + price[cur_node]

        def dfs2(cur_node, parent):
            nonlocal res
            if len(neighbors[cur_node]) == 1 and neighbors[cur_node][0] == parent:
                return
            if parent == -1:
                res = max(dis_to_leaf[cur_node] - price[cur_node], dis_to_non_leaf[cur_node])
            else:
                res = max(res, dis_to_leaf[cur_node])
            to_leaf, to_nonleaf = [], []
            for neighbor in neighbors[cur_node]:
                if neighbor == parent:
                    continue
                to_leaf.append([dis_to_leaf[neighbor], neighbor])
                to_nonleaf.append([dis_to_non_leaf[neighbor], neighbor])
                dfs2(neighbor, cur_node)

            if len(to_leaf) >= 2:
                to_leaf.sort(reverse=True)
                to_nonleaf.sort(reverse=True)
                if to_leaf[0][1] != to_nonleaf[0][1]:
                    res = max(res, to_leaf[0][0] + to_nonleaf[0][0] + price[cur_node])
                else:
                    res = max(res,
                              max(to_leaf[0][0] + to_nonleaf[1][0], to_leaf[1][0] + to_nonleaf[0][0]) + price[cur_node])

        dfs(0, -1)
        dfs2(0, -1)
        return res


if __name__ == "__main__":
    s = Solution()
    n, edges, price = 4, [[0, 3], [2, 1], [1, 3]], [6, 8, 2, 14]
    res = s.maxOutput(n, edges, price)
