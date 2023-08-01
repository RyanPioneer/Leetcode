"""
Source: https://rb.gy/9ck56
Date: 2023/8/1
Skill:
Ref:
Runtime: 311 ms, faster than 69.41%
Memory Usage: 18.92 MB, less than 34.12%
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
    def minimumCost(self, start: List[int], target: List[int], specialRoads: List[List[int]]) -> int:
        heap, res, dist = [[0, start[0], start[1]]], abs(target[0] - start[0]) + abs(target[1] - start[1]), defaultdict(int)
        heapify(heap)
        for road in specialRoads:
            heappush(heap, [abs(road[2] - start[0]) + abs(road[3] - start[1]), road[2], road[3]])

        while heap:
            dis, x, y = heappop(heap)
            if (x, y) not in dist:
                dist[(x, y)] = dis
                res = min(res, dis + abs(target[0] - x) + abs(target[1] - y))
                for road in specialRoads:
                    start_x, start_y, end_x, end_y, weight = road[0], road[1], road[2], road[3], road[4]
                    if (end_x, end_y) not in dist:
                        heappush(heap, [dis + abs(x - start_x) + abs(y - start_y) + weight, end_x, end_y])

        return res


if __name__ == "__main__":
    s = Solution()
