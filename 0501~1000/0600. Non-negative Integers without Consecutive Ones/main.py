"""
Source: https://rb.gy/qz0em
Date: 2023/8/14
Skill:
Ref:
Runtime: 40 ms, faster than 83.24%
Memory Usage: 16.34 MB, less than 54.19%
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
    def findIntegers(self, n: int) -> int:
        if n == 1:
            return 2
        s = bin(n)[2:]
        dp, sz, res = [[0 for _ in range(2)] for _ in range(len(s) + 1)], len(s), 0
        dp[1][0] = dp[1][1] = 1
        for i in range(2, sz + 1):
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1]
            dp[i][1] = dp[i - 1][0]
        for i in range(sz, 0, -1):
            if s[sz - i] == "1":
                res += dp[i][0]
                if sz - i + 1 < sz and s[sz - i + 1] == "1":    # ! Note!!!
                    res += dp[i - 1][0]
                    return res

        return res + 1


if __name__ == "__main__":
    s, n = Solution(), 5
    res = s.findIntegers(n)
    print(res)
