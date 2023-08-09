"""
Source: https://rb.gy/4cxpd
Date: 2023/8/9
Skill:
Ref:
Runtime: 3289 ms, faster than 43.28%
Memory Usage: 469.3 MB, less than 22.39%
Time complexity:
Space complexity:
Constraints:
    1 <= num.length <= 3500
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def numberOfCombinations(self, num: str) -> int:
        mod, sz = 10 ** 9 + 7, len(num)
        if num[0] == "0":
            return 0
        dp = [[0 for _ in range(sz + 1)] for _ in range(sz)]
        dp[0] = [1 for _ in range(sz + 1)]

        for i in range(1, sz):
            if num[i] >= num[i - 1] and num[i] != "0":
                dp[i][1] = dp[i - 1][1]
            for l in range(2, i + 1):
                dp[i][l] = dp[i][l - 1]
                if num[i - l + 1] == "0":
                    continue
                if l * 2 <= i + 1 and num[i - l + 1: i + 1] >= num[i - 2 * l + 1: i - l + 1]:
                    dp[i][l] += dp[i - l][l]
                else:
                    dp[i][l] += dp[i - l][min(l - 1, i + 1 - l)]
            dp[i][i + 1] = dp[i][i] + 1

        return dp[-1][-1] % mod


if __name__ == "__main__":
    s = Solution()
    num = "999999"   # "9999999999999"
    res = s.numberOfCombinations(num)
    print(res)
