"""
Source: https://rb.gy/ncb01
Date: 2023/7/26
Skill:
Ref:
Runtime: 1178 ms, faster than 49.29%
Memory Usage: 30.42 MB, less than 62.61%
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
    def brokenCalc(self, startValue: int, target: int) -> int:
        if startValue >= target:
            return startValue - target
        elif startValue * 2 > target:


if __name__ == "__main__":
    s = Solution()
    startValue, target = 3, 10
    res = s.brokenCalc(startValue, target)
