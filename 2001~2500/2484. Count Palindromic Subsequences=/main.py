"""
Source: https://rb.gy/qzc92
Date: 2023/7/14
Skill:
Ref:
Runtime: 2389 ms, faster than 7.97%
Memory Usage: 63.97 MB, less than 26.09%
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
    def countPalindromes(self, s: str) -> int:
        MOD, sz, res = 10 ** 9 + 7, len(s), 0
        dp1, dp2 = [[[0 for _ in range(10)] for _ in range(10)] for _ in range(sz)], \
            [[[0 for _ in range(10)] for _ in range(10)] for _ in range(sz)]
        forward_cnt, backward_cnt = [0 for _ in range(10)], [0 for _ in range(10)]

        forward_cnt[int(s[0])], backward_cnt[int(s[-1])] = 1, 1

        for i in range(1, sz):
            digit1, digit2 = int(s[i]), int(s[sz - i - 1])
            for j in range(10):
                for k in range(10):
                    dp1[i][j][k] = dp1[i-1][j][k]
                    dp2[sz - i - 1][j][k] = dp2[sz - i][j][k]
                    if digit1 == k:
                        dp1[i][j][k] += forward_cnt[j]
                    if digit2 == k:
                        dp2[sz - i - 1][j][k] += backward_cnt[j]
            forward_cnt[digit1] += 1
            backward_cnt[digit2] += 1

        for i in range(2, sz-2):
            for j in range(10):
                for k in range(10):
                    res += dp1[i-1][j][k] * dp2[i+1][j][k]

        return res % MOD


if __name__ == "__main__":
    s = Solution()
    res = s.countPalindromes("9999900000")
