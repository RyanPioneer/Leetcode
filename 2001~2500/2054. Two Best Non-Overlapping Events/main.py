"""
Source: https://rb.gy/8s843
Date: 2023/8/6
Skill:
Ref:
Runtime: 1461 ms, faster than 100.00%
Memory Usage: 59.38 MB, less than 93.83%
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
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda x: x[1])
        sz, res, prev = len(events), events[0][2], [[events[0][1]], [events[0][2]]]
        for i in range(1, sz):
            pos = bisect_left(prev[0], events[i][0])
            if pos > 0:
                res = max(res, events[i][2] + prev[1][pos - 1])
            else:
                res = max(res, events[i][2])
            if events[i][2] > prev[1][-1]:
                while prev[0] and events[i][1] == prev[0][-1]:
                    prev[1].pop()
                    prev[0].pop()
                prev[0].append(events[i][1])
                prev[1].append(events[i][2])
        return res


if __name__ == "__main__":
    s = Solution()
    events = [[6, 6, 6], [7, 9, 4], [4, 5, 4], [3, 7, 9], [6, 10, 8], [4, 7, 6]]
    res = s.maxTwoEvents(events)
