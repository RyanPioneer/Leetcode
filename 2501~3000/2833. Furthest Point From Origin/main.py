"""
Source: https://rb.gy/esq6p
Date: 2023/8/27
Skill:
Runtime: 33 ms, faster than 100%
Memory Usage: 16.3 MB, less than 25%
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
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        left, right, space = 0, 0, 0
        for c in moves:
            if c == "L":
                left += 1
            elif c == "R":
                right += 1
            else:
                space += 1
        return max(left, right) - min(left, right) + space


if __name__ == "__main__":
    s = Solution()
