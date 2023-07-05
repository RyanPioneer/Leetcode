"""
Source: https://rb.gy/3xmmk
Date: 2023/7/5
Skill:
Ref:
Runtime: 79 ms, faster than 72.43%
Memory Usage: 17.4 MB, less than 69.22%
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
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [[sys.maxsize for _ in range(len(triangle))] for _ in range(2)]
        dp[0][0] = triangle[0][0]
        for i in range(1, len(triangle)):
            dp[1][0] = dp[0][0] + triangle[i][0]
            for j in range(1, i):
                dp[1][j] = min(dp[0][j-1], dp[0][j]) + triangle[i][j]
            dp[1][i] = dp[0][i - 1] + triangle[i][i]
            dp[0] = list(dp[1])
        return min(dp[0])


if __name__ == "__main__":
    s = Solution()
