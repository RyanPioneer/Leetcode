"""
Source: https://rb.gy/t0jjq
Date: 2023/8/25
Skill:
Runtime: TLE
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    1 <= k <= jobs.length <= 12
    1 <= jobs[i] <= 10 ** 7
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        sz = len(jobs)
        state_time, dp = [0 for _ in range(1 << sz)], [[sys.maxsize for _ in range(1 << sz)] for _ in range(k + 1)]
        dp[0][0] = 0
        for i in range(1, 1 << sz):
            time = 0
            for j in range(sz):
                if i & (1 << j) != 0:
                    time += jobs[j]
            state_time[i] = time

        for i in range(1, k + 1):
            for j in range(1, 1 << sz):
                k = j
                while k > 0:
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j - k], state_time[k]))
                    k = (k - 1) & j

        return dp[-1][-1]


if __name__ == "__main__":
    s = Solution()
    jobs, k = [1, 2, 4, 7, 8], 2
    res = s.minimumTimeRequired(jobs, k)
    print(res)
