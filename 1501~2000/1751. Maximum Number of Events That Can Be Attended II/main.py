"""
Source: https://rb.gy/qepxi
Date: 2023/7/12
Skill:
Ref:
Runtime: 1049 ms, faster than 53.38%
Memory Usage: 61.2 MB, less than 95.49%
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
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort(key=lambda x: x[1])
        events.insert(0, [events[0][0], events[0][1], -sys.maxsize])
        res, sz, end_time = 0, len(events), [0]
        dp = [[0 for _ in range(k+1)] for _ in range(sz)]
        for i in range(1, sz):
            idx = bisect_left(end_time, events[i][0])
            for j in range(1, k+1):
                dp[i][j] = max(dp[i-1][j], dp[idx-1][j-1] + events[i][2])
            end_time.append(events[i][1])
        return max(dp[sz-1])


if __name__ == "__main__":
    s = Solution()
