"""
Source: https://leetcode.com/problems/ipo/
Date: 2023/2/24
Skill:
Ref:
Runtime: 1163 ms, faster than 40.90%
Memory Usage: 35.6 MB, less than 96.88%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        tasks, heap, sz, idx = [], [], len(profits), 0
        for i in range(sz):
            tasks.append([capital[i], profits[i]])

        tasks.sort()

        heapify(heap)
        for i in range(k):
            while idx < sz and tasks[idx][0] <= w:
                heappush(heap, -tasks[idx][1])
                idx += 1
            if len(heap) == 0:
                break
            num = heappop(heap)
            w += -num

        return w


if __name__ == "__main__":
    s = Solution