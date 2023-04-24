"""
Source: https://leetcode.com/problems/restore-the-array/
Date: 2023/4/23
Skill: Dynamic Programming
Ref:
Runtime: 4122 ms, faster than 5.48%
Memory Usage: 485.6 MB, less than 5.48%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10 ** 5
    1 <= k <= 10 ** 9
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        MOD, res, sz, digit, num = 10 ** 9 + 7, 0, len(s), 0, k
        dp = [0 for _ in range(sz + 1)]
        dp[0] = 1
        while num > 0:
            num //= 10
            digit += 1

        def check(string):
            return 1 <= int(string) <= k

        for i in range(sz):
            num = 0
            for length in range(min(i + 1, digit)):
                if s[i - length] == "0":
                    continue
                if check(s[i - length: i + 1]):
                    num += dp[i - length]
                else:
                    break
            dp[i + 1] = num

        return dp[sz] % MOD


if __name__ == "__main__":
    s = Solution()
