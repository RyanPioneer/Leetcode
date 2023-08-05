"""
Source: https://rb.gy/8s843
Date: 2023/8/5
Skill:
Ref:
Runtime: 1432 ms, faster than 72.23%
Memory Usage: 29.7 MB, less than 19.71%
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
        sz, res, idx, q = len(events), events[0][2], 0, deque()
        for i in range(1, sz):
            while q and events[i][0] > events[q[0]][1]:
                idx = q.popleft()
            if events[i][0] > events[idx][1]:
                res = max(res, events[i][2] + events[idx][2])
            else:
                res = max(res, events[i][2])
            if events[i][2] > events[idx][2]:
                if not q or events[i][2] > events[q[-1]][2]:
                    q.append(i)

        return res


if __name__ == "__main__":
    s = Solution()
    events = [[6, 6, 6], [7, 9, 4], [4, 5, 4], [3, 7, 9], [6, 10, 8], [4, 7, 6]]
    res = s.maxTwoEvents(events)
