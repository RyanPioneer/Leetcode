"""
Source: https://rb.gy/8ib5d
Date: 2023/7/23
Skill:
Ref:
Runtime: 6084 ms, faster than 20.00%
Memory Usage: 18.55 MB, less than 60.00%
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
    def numberOfWays(self, n: int, x: int) -> int:
        MOD = 10 ** 9 + 7
        dp, nums = [[0 for _ in range(n+1)] for _ in range(n+1)], []
        dp[0] = [1 for _ in range(n+1)]
        for i in range(n+1):
            num = 1
            for j in range(x):
                num *= i
            nums.append(num)

        for i in range(1, n+1):
            for j in range(1, n+1):
                dp[i][j] = dp[i][j-1]
                if nums[j] <= i:
                    dp[i][j] += dp[i-nums[j]][j-1]

        return dp[n][n] % MOD


if __name__ == "__main__":
    s = Solution()
    n, x = 4, 1
    res = s.numberOfWays(n, x)
