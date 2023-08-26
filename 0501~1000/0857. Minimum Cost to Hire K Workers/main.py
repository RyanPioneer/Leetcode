"""
Source: https://rb.gy/kvbnd
Date: 2023/8/26
Skill:
Runtime: 180 ms, faster than 72.88%
Memory Usage: 19.1 MB, less than 41.83%
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
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        person, res, sz, heap, cur_sum = [], 0, len(quality), [], 0
        heapify(heap)
        for i in range(sz):
            person.append([wage[i] / quality[i], quality[i]])
        person.sort(key=lambda x: x[0])
        for i in range(k):
            cur_sum += person[i][1]
            heappush(heap, -person[i][1])

        res = cur_sum * person[k - 1][0]
        for i in range(k, sz):
            if person[i][1] < -heap[0]:
                cur_sum += person[i][1] + heap[0]
                heappop(heap)
                heappush(heap, -person[i][1])
                res = min(res, cur_sum * person[i][0])

        return res


if __name__ == "__main__":
    s = Solution()
