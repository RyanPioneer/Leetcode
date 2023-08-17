"""
Source: https://rb.gy/zyltq
Date: 2023/8/17
Skill:
Ref:
Runtime: 1275 ms, faster than 29.90%
Memory Usage: 17.11 MB, less than 31.86%
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


class MyCalendarThree:

    def __init__(self):
        from sortedcontainers import SortedDict
        self.mydict = SortedDict()

    def book(self, startTime: int, endTime: int) -> int:
        if startTime in self.mydict:
            self.mydict[startTime] += 1
        else:
            self.mydict[startTime] = 1
        if endTime in self.mydict:
            self.mydict[endTime] -= 1
        else:
            self.mydict[endTime] = -1
        res, cur = 0, 0
        for key, val in self.mydict.items():
            cur += val
            res = max(res, cur)
        return res


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(startTime,endTime)
