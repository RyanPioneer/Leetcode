"""
Source: https://rb.gy/mpvb7
Date: 2023/7/8
Skill:
Ref:
Runtime: 1749 ms, faster than 63.48%
Memory Usage: 79 MB, less than 85.22%
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
    def longestString(self, x: int, y: int, z: int) -> int:
        return min(x, y) * 4 + min(abs(x - y), 1) * 2 + z * 2


if __name__ == "__main__":
    s = Solution()

