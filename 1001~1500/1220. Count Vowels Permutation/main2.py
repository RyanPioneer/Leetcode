"""
Source: https://rb.gy/orxun
Date: 2023/8/21
Skill:
Ref:
Runtime: 117 ms, faster than 94.20%
Memory Usage: 16.45 MB, less than 75.57%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 2 * 10 ** 4
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right
from functools import cache


class Solution:
    def countVowelPermutation(self, n: int) -> int:
        mod = 10 ** 9 + 7
        dp = [1 for _ in range(5)]
        for i in range(1, n):
            temp = dp.copy()
            dp[0] = (temp[1] + temp[2] + temp[4]) % mod
            dp[1] = (temp[0] + temp[2]) % mod
            dp[2] = (temp[1] + temp[3]) % mod
            dp[3] = temp[2] % mod
            dp[4] = (temp[2] + temp[3]) % mod

        return sum(dp) % mod


if __name__ == "__main__":
    s = Solution()
