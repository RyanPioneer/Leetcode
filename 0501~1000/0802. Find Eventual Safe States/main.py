"""
Source: https://rb.gy/vx6yl
Date: 2023/7/12
Skill:
Ref:
Runtime: 678 ms, faster than 55.94%
Memory Usage: 24.4 MB, less than 28.72%
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
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        # 0: unvisited, 1: visited in this dfs, 2: unsafe, 3: safe
        visited, res = [0 for _ in range(len(graph))], []
        def dfs(idx):
            if visited[idx] == 1:
                visited[idx] = 2
                return False
            elif visited[idx] == 2:
                return False
            elif visited[idx] == 3:
                return True
            else:
                visited[idx] = 1
                for next in graph[idx]:
                    if not dfs(next):
                        visited[idx] = 2
                        return False
                visited[idx] = 3
                return True

        for i in range(len(graph)):
            if dfs(i):
                res.append(i)
        return res


if __name__ == "__main__":
    s = Solution()
