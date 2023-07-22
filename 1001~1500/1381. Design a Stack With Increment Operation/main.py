"""
Source: https://rb.gy/y7j5z
Date: 2023/7/22
Skill:
Ref:
Runtime: 134 ms, faster than 45.11%
Memory Usage: 17.28 MB, less than 82.11%
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


class CustomStack:

    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.q = deque()

    def push(self, x: int) -> None:
        if len(self.q) < self.maxSize:
            self.q.append(x)

    def pop(self) -> int:
        if self.q:
            return self.q.pop()
        else:
            return -1

    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, len(self.q))):
            self.q[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)


if __name__ == "__main__":
    maxSize = 2
    s = CustomStack(maxSize)
