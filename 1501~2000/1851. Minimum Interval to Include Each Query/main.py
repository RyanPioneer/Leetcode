"""
Source: https://rb.gy/ai0qg
Date: 2023/8/26
Skill:
Runtime: 1602 ms, faster than 53.31%
Memory Usage: 68.24 MB, less than 5.04%
Time complexity:
Space complexity:
Constraints:

"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        q, sz, res, heap, idx = [], len(queries), [-1 for _ in range(len(queries))], [], 0
        for i in range(sz):
            q.append([queries[i], i])
        q.sort(key=lambda x: x[0])
        intervals.sort(key=lambda x: x[0])
        for i in range(sz):
            while idx < len(intervals) and intervals[idx][0] <= q[i][0]:
                heappush(heap, [intervals[idx][1] - intervals[idx][0], intervals[idx][0]])
                idx += 1
            while len(heap) > 0 and heap[0][0] + heap[0][1] < q[i][0]:
                heappop(heap)
            if len(heap) > 0:
                res[q[i][1]] = heap[0][0] + 1

        return res


if __name__ == "__main__":
    s = Solution()
    intervals, queries = [[1, 4], [2, 4], [3, 6], [4, 4]], [2, 3, 4, 5]
    res = s.minInterval(intervals, queries)
    print(res)
