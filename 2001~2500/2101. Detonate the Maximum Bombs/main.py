"""
Source: https://leetcode.com/problems/detonate-the-maximum-bombs/
Date: 2023/4/10
Skill:
Ref:
Runtime: 1038 ms, faster than 32.75%
Memory Usage: 14.8 MB, less than 20.57%
Time complexity:
Space complexity:
Constraints:
    1 <= bombs.length <= 100
    bombs[i].length == 3
    1 <= xi, yi, ri <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        def check_distance(i, j):   # * check if i can trigger j
            x, y = abs(bombs[i][0] - bombs[j][0]), abs(bombs[i][1] - bombs[j][1])
            return math.sqrt(x ** 2 + y ** 2) <= bombs[i][2]

        sz, res = len(bombs), 0
        graph = [set() for _ in range(sz)]
        for i in range(sz - 1):
            for j in range(i + 1, sz):
                if check_distance(i, j):
                    graph[i].add(j)
                if check_distance(j, i):
                    graph[j].add(i)

        for i in range(sz):
            visited = [0 for _ in range(sz)]
            visited[i], q = 1, deque([i])
            local_res = 1
            while q:
                cur_node = q.popleft()
                for neighbor in graph[cur_node]:
                    if visited[neighbor] == 0:
                        visited[neighbor] = 1
                        local_res += 1
                        q.append(neighbor)
            res = max(res, local_res)

        return res


if __name__ == "__main__":
    s = Solution()
    bombs = [[54, 95, 4], [99, 46, 3], [29, 21, 3], [96, 72, 8], [49, 43, 3], [11, 20, 3], [2, 57, 1], [69, 51, 7],
             [97, 1, 10], [85, 45, 2], [38, 47, 1], [83, 75, 3], [65, 59, 3], [33, 4, 1], [32, 10, 2], [20, 97, 8],
             [35, 37, 3]]
    res = s.maximumDetonation(bombs)
