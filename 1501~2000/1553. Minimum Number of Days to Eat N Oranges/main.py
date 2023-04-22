"""
Source: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/
Date: 2023/4/22
Skill:
Ref:
Runtime: TLE
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 2 * 10^9
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minDays(self, n: int) -> int:
        dp = [math.inf for _ in range(n + 1)]
        dp[0], dp[1] = 0, 1
        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + 1
            if i % 2 == 0:
                dp[i] = min(dp[i], dp[i // 2] + 1)
            if i % 3 == 0:
                dp[i] = min(dp[i], dp[i - i // 3 * 2] + 1)

        return dp[n]


if __name__ == "__main__":
    s = Solution()
