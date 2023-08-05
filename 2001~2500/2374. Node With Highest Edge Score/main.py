"""
Source: https://rb.gy/hgqgp
Date: 2023/8/4
Skill:
Ref:
Runtime: 1007 ms, faster than 97.27%
Memory Usage: 30.27 MB, less than 85.45%
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
    def edgeScore(self, edges: List[int]) -> int:
        nums, sz, res = [0 for _ in range(len(edges))], len(edges), 0
        for i in range(1, sz):
            nums[edges[i]] += i
        for i in range(1, sz):
            if nums[i] > nums[res]:
                res = i
        return res


if __name__ == "__main__":
    s = Solution()
