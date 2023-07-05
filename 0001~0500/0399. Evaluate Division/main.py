"""
Source: https://rb.gy/qh4gq
Date: 2023/7/5
Skill:
Ref:
Runtime: 49 ms, faster than 47.40%
Memory Usage: 16.4 MB, less than 31.62%
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
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        next_position, visited = defaultdict(list), set()
        for i in range(len(equations)):
            equation = equations[i]
            next_position[equation[0]].append([equation[1], values[i]])
            next_position[equation[1]].append([equation[0], 1 / values[i]])

        def dfs(start, end, cur_value):
            for next in next_position[start]:
                if next[0] == end:
                    return cur_value * next[1]
                if next[0] not in visited:
                    visited.add(next[0])
                    dis = dfs(next[0], end, cur_value * next[1])
                    if dis != -1:
                        return dis
                    visited.remove(next[0])
            return -1

        res = []
        for query in queries:
            visited.add(query[0])
            res.append(dfs(query[0], query[1], 1))
            visited.clear()

        return res


if __name__ == "__main__":
    s = Solution()
