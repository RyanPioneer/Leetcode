"""
Source: https://rb.gy/395gs
Date: 2023/8/11
Skill:
Ref:
Runtime: 126 ms, faster than 94.83%
Memory Usage: 16.47 MB, less than 89.60%
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
    def change(self, amount: int, coins: List[int]) -> int:
        dp, sz = [0 for _ in range(amount + 1)], len(coins)
        dp[0] = 1
        for i in range(sz):
            for j in range(coins[i], amount + 1):
                dp[j] += dp[j - coins[i]]
        return dp[-1]


if __name__ == "__main__":
    s = Solution()
