"""
Source: https://rb.gy/tgau5
Date: 2023/7/12
Skill:
Ref:
Runtime: 1666 ms, faster than 91.28%
Memory Usage: 36.4 MB, less than 71.28%
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
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        rides.sort(key=lambda x: x[1])
        rides.insert(0, [0, 0, 0])
        end_point, sz = [0], len(rides)
        dp = [0 for _ in range(sz)]
        for i in range(1, sz):
            prev = bisect_right(end_point, rides[i][0]) - 1
            dp[i] = max(dp[i-1], dp[prev] + rides[i][1] - rides[i][0] + rides[i][2])
            end_point.append(rides[i][1])
        return dp[sz-1]


if __name__ == "__main__":
    s = Solution()
