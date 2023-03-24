"""
Source: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
Date: 2023/3/24
Skill:
Runtime: 1244 ms, faster than 69.33%
Memory Usage: 46.1 MB, less than 70.67%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 5 * 10^4
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        res, in_edges, out_edges = 0, [set() for _ in range(n)], [set() for _ in range(n)]
        for connection in connections:
            in_edges[connection[0]].add(connection[1])
            out_edges[connection[1]].add(connection[0])

        q = deque([0])
        while q:
            cur = q.popleft()
            for next_node in out_edges[cur]:
                in_edges[next_node].remove(cur)
                q.append(next_node)
            for next_node in in_edges[cur]:
                res += 1
                out_edges[next_node].remove(cur)
                q.append(next_node)

        return res


if __name__ == "__main__":
    s = Solution()
