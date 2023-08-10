"""
Source: https://rb.gy/ge8jc
Date: 2023/8/10
Skill:
Ref:
Runtime: 325 ms, faster than 95.90%
Memory Usage: 18.85 MB, less than 47.18%
Time complexity:
Space complexity:
Constraints:
    1 <= values.length <= 1000
    0 <= edges.length <= 2000
    There are at most four edges connected to each node.
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        neighbors, n, res = [[] for _ in range(len(values))], len(values), 0
        for edge in edges:
            neighbors[edge[0]].append([edge[1], edge[2]])
            neighbors[edge[1]].append([edge[0], edge[2]])
        visited, visited_time = defaultdict(int), [0 for _ in range(n)]
        shortest_path, heap = [-1 for _ in range(n)], [[0, 0]]
        heapify(heap)
        while heap:
            [dis, pos] = heappop(heap)
            if shortest_path[pos] != -1:
                continue
            shortest_path[pos] = dis
            for neighbor in neighbors[pos]:
                if shortest_path[neighbor[0]] == -1:
                    heappush(heap, [dis + neighbor[1], neighbor[0]])

        def back_tracking(idx, cur_val, cost, budget):
            nonlocal res
            res = max(res, cur_val)
            if idx == 0:
                budget -= cost
                cost = 0
            for i in range(len(neighbors[idx])):
                [next, time] = neighbors[idx][i]
                if time + cost + shortest_path[next] > budget or (idx, next) in visited:
                    continue
                visited[(idx, next)] = 1
                visited_time[next] += 1
                if visited_time[next] == 1:
                    back_tracking(next, cur_val + values[next], cost + time, budget)
                else:
                    back_tracking(next, cur_val, cost + time, budget)
                del visited[(idx, next)]
                visited_time[next] -= 1

        visited_time[0] = 1
        back_tracking(0, values[0], 0, maxTime)
        return res


if __name__ == "__main__":
    s = Solution()
    values, edges, maxTime = [0, 32, 10, 43], [[0, 3, 10], [1, 2, 15], [0, 1, 10]], 49
    res = s.maximalPathQuality(values, edges, maxTime)
    print(res)
