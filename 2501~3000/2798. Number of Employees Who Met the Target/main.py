"""
Source: https://rb.gy/hcac4
Date: 2023/7/30
Skill:
Ref:
Runtime: 43 ms, faster than 100.00%
Memory Usage: 16.32 MB, less than 16.67%
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
    def numberOfEmployeesWhoMetTarget(self, hours: List[int], target: int) -> int:
        res = 0
        for hour in hours:
            if hour >= target:
                res += 1
        return res


if __name__ == "__main__":
    s = Solution()
