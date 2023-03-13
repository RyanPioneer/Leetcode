"""
Source: https://leetcode.com/problems/trapping-rain-water-ii/
Date: 2023/3/11
Skill:
Runtime: 372 ms, faster than 97.90%
Memory Usage: 16.1 MB, less than 50.92%
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
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        m, n, heap = len(heightMap), len(heightMap[0]), []
        visited = [[0 for _ in range(n)] for _ in range(m)]
        heapify(heap)
        for i in range(1, m-1):
            heappush(heap, (heightMap[i][0], i, 0))
            heappush(heap, (heightMap[i][n-1], i, n-1))
            visited[i][0] = visited[i][n-1] = 1

        for i in range(n):
            heappush(heap, (heightMap[0][i], 0, i))
            heappush(heap, (heightMap[m-1][i], m-1, i))
            visited[0][i] = visited[m-1][i] = 1

        res, cur_height = 0, 0
        direction = [0, 1, 0, -1, 0]

        while heap:
            height, x, y = heappop(heap)
            if cur_height < height:
                cur_height = height
            res += cur_height - height
            for i in range(4):
                next_x, next_y = x + direction[i], y + direction[i+1]
                if next_x < 0 or next_x >= m or next_y < 0 or next_y >= n \
                        or visited[next_x][next_y]:
                    continue
                heappush(heap, (heightMap[next_x][next_y], next_x, next_y))
                visited[next_x][next_y] = 1

        return res


if __name__ == "__main__":
    s = Solution()
