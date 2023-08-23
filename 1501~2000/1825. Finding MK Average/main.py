"""
Source: https://rb.gy/z1qd3
Date: 2023/8/23
Skill:
Ref:
Runtime: 9173 ms, faster than 5.30%
Memory Usage: 51.97 MB, less than 63.64%
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


class MKAverage:

    def __init__(self, m: int, k: int):
        self.m, self.k = m, k
        from sortedcontainers import SortedList
        self.sl = SortedList()
        self.q = deque()

    def addElement(self, num: int) -> None:
        self.q.append(num)
        self.sl.add(num)
        if len(self.q) > self.m:
            target = self.q.popleft()
            self.sl.remove(target)

    def calculateMKAverage(self) -> int:
        if len(self.sl) < self.m:
            return -1
        return sum(self.sl[self.k: self.m - self.k]) // (self.m - 2 * self.k)


# Your MKAverage object will be instantiated and called as such:
# obj = MKAverage(m, k)
# obj.addElement(num)
# param_2 = obj.calculateMKAverage()


if __name__ == "__main__":
    s = MKAverage()
