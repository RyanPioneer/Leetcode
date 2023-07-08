"""
Source: https://rb.gy/zkg85
Date: 2023/7/8
Skill:
Ref:
Runtime: 194 ms, faster than 90.17%
Memory Usage: 17.4 MB, less than 44.3%
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
    def minimumCost(self, s: str) -> int:
        sz, res = len(s), 0
        for i in range(1, sz):
            if s[i] != s[i-1]:
                res += min(i, sz - i)
        return res


if __name__ == "__main__":
    s = Solution()

