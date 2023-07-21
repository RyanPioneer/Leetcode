"""
Source: https://rb.gy/6dx47
Date: 2023/7/21
Skill:
Ref:
Runtime: 2418 ms, faster than 40.87%
Memory Usage: 16.74 MB, less than 33.71%
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
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        res, sz = [0 for _ in range(len(queries))], len(queries)
        for point in points:
            for i in range(sz):
                x, y = (point[0] - queries[i][0]) ** 2, (point[1] - queries[i][1]) ** 2
                if math.sqrt(x + y) <= queries[i][2]:
                    res[i] += 1

        return res


if __name__ == "__main__":
    s = Solution()
