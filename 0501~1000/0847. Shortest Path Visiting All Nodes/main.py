"""
Source: https://rb.gy/na3fc
Date: 2023/8/13
Skill:
Ref:
Runtime: 2659 ms, faster than 5.01%
Memory Usage: 22.78 MB, less than 27.14%
Time complexity:
Space complexity:
Constraints:
    1 <= graph.length <= 12
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n, res = len(graph), sys.maxsize
        target, visited = (1 << n) - 1, defaultdict(int)

        def dfs(pos, cur_state, step):
            nonlocal res
            if cur_state == target:
                res = min(res, step)
                return
            for neighbor in graph[pos]:
                next_state = cur_state
                if next_state & (1 << neighbor) == 0:
                    next_state += (1 << neighbor)
                if (next_state, neighbor) not in visited or step + 1 < visited[(next_state, neighbor)]:
                    visited[(next_state, neighbor)] = step + 1
                    dfs(neighbor, next_state, step + 1)

        for i in range(n):
            start = 1 << i
            visited[(start, i)] = 0
            dfs(i, start, 0)
        return res


if __name__ == "__main__":
    s = Solution()
    graph = [[1, 2, 3], [0], [0], [0]]
    res = s.shortestPathLength(graph)
    print(res)
