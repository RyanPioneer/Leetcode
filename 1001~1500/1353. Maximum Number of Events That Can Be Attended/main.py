"""
Source: https://rb.gy/7xr51
Date: 2023/7/12
Skill:
Ref:
Runtime: 1149 ms, faster than 51.31%
Memory Usage: 64 MB, less than 44.21%
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
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda x: (x[0], x[1]))
        h, res, cur_time, idx, sz = [], 0, events[0][0], 0, len(events)
        heapify(h)
        while idx < sz or h:
            while idx < sz and events[idx][0] <= cur_time:
                heappush(h, events[idx][1])
                idx += 1
            while h and h[0] < cur_time:
                heappop(h)
            if h:
                heappop(h)
                res += 1
            cur_time += 1

        return res


if __name__ == "__main__":
    s = Solution()
    events = [[1, 10], [2, 2], [2, 2], [2, 2], [2, 2]]
    res = s.maxEvents(events)
