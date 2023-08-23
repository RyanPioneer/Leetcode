"""
Source: https://rb.gy/1zhdp
Date: 2023/8/23
Skill:
Ref:
Runtime: 764 ms, faster than 99.11%
Memory Usage: 40.5 MB, less than 46.2%
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
from functools import cache


class SORTracker:

    def __init__(self):
        self.time = 0
        from sortedcontainers import SortedList
        self.sl = SortedList()

    def add(self, name: str, score: int) -> None:
        self.sl.add([-score, name])

    def get(self) -> str:
        self.time += 1
        return self.sl[self.time - 1][1]

# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()


if __name__ == "__main__":
    s = SORTracker()
