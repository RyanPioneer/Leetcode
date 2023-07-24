"""
Source: https://rb.gy/549ii
Date: 2023/7/24
Skill:
Ref:
Runtime: 2292 ms, faster than 33.90%
Memory Usage: 87.12 MB, less than 76.27%
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
    def minimumWeight(self, n: int, edges: List[List[int]], src1: int, src2: int, dest: int) -> int:
        next, prev, res = [[] for _ in range(n)], [[] for _ in range(n)], sys.maxsize // 3
        for edge in edges:
            next[edge[0]].append((edge[1], edge[2]))
            prev[edge[1]].append((edge[0], edge[2]))

        def dijkstra(src, neighbors):
            heap = [(0, src)]
            heapify(heap)
            dis = [sys.maxsize // 3 for _ in range(n)]
            while heap:
                cur_dis, cur_pos = heappop(heap)
                if dis[cur_pos] < sys.maxsize // 3:
                    continue
                dis[cur_pos] = cur_dis
                for neighbor_node, neighbor_dis in neighbors[cur_pos]:
                    if dis[neighbor_node] == sys.maxsize // 3:
                        heappush(heap, (cur_dis + neighbor_dis, neighbor_node))
            return dis

        dis1, dis2, dis3 = dijkstra(src1, next), dijkstra(src2, next), dijkstra(dest, prev)
        for i in range(n):
            res = min(dis1[i] + dis2[i] + dis3[i], res)

        return res if res < sys.maxsize // 3 else -1


if __name__ == "__main__":
    s = Solution()
