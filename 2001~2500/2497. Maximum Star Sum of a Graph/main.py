"""
Source: https://rb.gy/yqaua
Date: 2023/8/4
Skill:
Ref:
Runtime: 1454 ms, faster than 71.90%
Memory Usage: 70.31 MB, less than 7.84%
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
import functools


class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        neighbors, sz, res = [[] for _ in range(len(vals))], len(vals), -sys.maxsize
        for edge in edges:
            heappush(neighbors[edge[0]], [-vals[edge[1]], edge[1]])
            heappush(neighbors[edge[1]], [-vals[edge[0]], edge[0]])
        for i in range(sz):
            num, cnt = vals[i], 0
            while neighbors[i] and cnt < k:
                [val, _] = heappop(neighbors[i])
                if val >= 0:
                    break
                num -= val
                cnt += 1
            res = max(res, num)

        return res


if __name__ == "__main__":
    s = Solution()
