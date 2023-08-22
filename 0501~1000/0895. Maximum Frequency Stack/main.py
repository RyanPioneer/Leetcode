"""
Source: https://rb.gy/ec7qn
Date: 2023/8/22
Skill:
Runtime: 312 ms, faster than 47.24%
Memory Usage: 24.97 MB, less than 39.98%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class FreqStack:

    def __init__(self):
        self.heap = []
        heapify(self.heap)
        self.time = 0
        self.num2freq = defaultdict(int)

    def push(self, val: int) -> None:
        self.time -= 1
        self.num2freq[val] -= 1
        heappush(self.heap, [self.num2freq[val], self.time, val])

    def pop(self) -> int:
        freq, time, val = heappop(self.heap)
        self.num2freq[val] += 1
        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()


if __name__ == "__main__":
    s = FreqStack()
