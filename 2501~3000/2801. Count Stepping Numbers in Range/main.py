"""
Source: https://rb.gy/m9big
Date: 2023/7/30
Skill:
Ref:
Runtime: 132 ms, faster than 100.00%
Memory Usage: 17.27 MB, less than 100.00%
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
    def countSteppingNumbers(self, low: str, high: str) -> int:
        sz1, sz2, MOD = len(high), len(low), 10 ** 9 + 7
        dp = [[0 for _ in range(10)] for _ in range(sz1)]
        for i in range(10):
            dp[0][i] = 1
        for i in range(1, sz1):
            dp[i][0] = dp[i - 1][1]
            for j in range(1, 9):
                dp[i][j] = dp[i - 1][(j + 1) % 10] + dp[i - 1][(j - 1) % 10]
            dp[i][9] = dp[i - 1][8]

        def dfs(num, idx):
            if idx == len(num) - 1:
                return 1
            total, length, cur_num = 0, len(num), int(num[idx])
            if cur_num > 0:
                if cur_num - 1 < int(num[idx + 1]):
                    total += dp[length - idx - 2][cur_num - 1]
                elif cur_num - 1 == int(num[idx + 1]):
                    total += dfs(num, idx + 1)
            if cur_num < 9:
                if cur_num + 1 < int(num[idx + 1]):
                    total += dp[length - idx - 2][cur_num + 1]
                elif cur_num + 1 == int(num[idx + 1]):
                    total += dfs(num, idx + 1)
            return total

        def find_num(num):
            total, length = 0, len(num)
            if length == 1:
                return int(num)
            for i in range(length - 1):
                for j in range(9):
                    total += dp[i][j + 1]
            for i in range(1, int(num[0])):
                total += dp[length - 1][i]
            total += dfs(num, 0)
            return total

        return (find_num(high) - find_num(str(int(low) - 1))) % MOD


if __name__ == "__main__":
    s = Solution()
    low, high = "90", "101"
    res = s.countSteppingNumbers(low, high)
    print(res)
