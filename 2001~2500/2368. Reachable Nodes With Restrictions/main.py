"""
Source: https://rb.gy/x2668
Date: 2023/7/23
Skill:
Ref:
Runtime: 1604 ms, faster than 94.61%
Memory Usage: 81.04 MB, less than 66.53%
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
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        neighbors, visited, res, q = defaultdict(list), [0 for _ in range(n)], 1, deque([0])
        for edge in edges:
            neighbors[edge[0]].append(edge[1])
            neighbors[edge[1]].append(edge[0])
        for i in restricted:
            visited[i] = 1
        visited[0] = 1

        while q:
            cur_node = q.popleft()
            for neighbor in neighbors[cur_node]:
                if visited[neighbor] == 0:
                    q.append(neighbor)
                    visited[neighbor] = 1
                    res += 1

        return res


if __name__ == "__main__":
    s = Solution()
