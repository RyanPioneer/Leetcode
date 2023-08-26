"""
Source: https://rb.gy/msko7
Date: 2023/8/26
Skill:
Runtime: TLE
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 10
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        n, mod, dp = len(hats), 10 ** 9 + 7, defaultdict(int)
        state = (1 << 40) - 1

        def dfs(idx, cur_state):
            if idx == n:
                return 1
            if cur_state in dp:
                return dp[cur_state]
            res = 0
            for i in range(len(hats[idx])):
                num = 1 << (hats[idx][i] - 1)
                if cur_state & num != 0:
                    res += dfs(idx + 1, cur_state - num) % mod

            dp[cur_state] = res % mod
            return dp[cur_state]

        return dfs(0, state)


if __name__ == "__main__":
    s = Solution()
    hats = [[3, 4], [4, 5], [5]]
    res = s.numberWays(hats)
    print(res)
