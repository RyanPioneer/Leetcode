"""
Source: https://rb.gy/7m47z
Date: 2023/8/13
Skill:
Ref:
Runtime: 399 ms, faster than 93.33%
Memory Usage: 22.04 MB, less than 80.58%
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
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        cur_max, sz, res = values[0], len(values), 0
        for i in range(1, sz):
            res = max(res, cur_max + values[i] - i)
            cur_max = max(cur_max, values[i] + i)
        return res


if __name__ == "__main__":
    s = Solution()

