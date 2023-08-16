"""
Source: https://rb.gy/3b22r
Date: 2023/8/16
Skill:
Ref:
Runtime: 1221 ms, faster than 84.29%
Memory Usage: 33.86 MB, less than 68.83%
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
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        sz, res, maxlen = len(obstacles), [], 0
        dp = [sys.maxsize for _ in range(sz + 1)]
        dp[0] = -sys.maxsize
        for obstacle in obstacles:
            if obstacle >= dp[maxlen]:
                maxlen += 1
                dp[maxlen] = obstacle
                res.append(maxlen)
            else:
                pos = bisect_right(dp, obstacle)
                dp[pos] = obstacle
                res.append(pos)

        return res


if __name__ == "__main__":
    s = Solution()

