"""
Source: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/
Date: 2023/3/11
Skill:
Runtime: 1615 ms, faster than 50.74%
Memory Usage: 29.1 MB, less than 77.61%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        heap, sorted_queries = [[grid[0][0], 0, 0]], []
        m, n, res = len(grid), len(grid[0]), [0 for _ in range(len(queries))]
        for i in range(len(queries)):
            sorted_queries.append([queries[i], i])

        sorted_queries.sort()
        heapify(heap)
        cur_num = 0
        direction = [0, 1, 0, -1, 0]
        visited = [[0 for _ in range(n)] for _ in range(m)]
        visited[0][0] = 1
        for query in sorted_queries:
            while heap:
                if query[0] > heap[0][0]:
                    cur_num += 1
                    num, x, y = heappop(heap)
                    for i in range(4):
                        if 0 <= x + direction[i] < m and \
                                0 <= y + direction[i + 1] < n \
                                and not visited[x + direction[i]][y + direction[i + 1]]:
                            heappush(heap, [grid[x + direction[i]][y + direction[i + 1]],
                                            x + direction[i], y + direction[i + 1]])
                            visited[x+direction[i]][y+direction[i+1]] = 1
                else:
                    break

            res[query[1]] = cur_num

        return res


if __name__ == "__main__":
    s = Solution()
