"""
Source: https://rb.gy/mp9ep
Date: 2023/8/7
Skill:
Ref:
Runtime: 1044 ms, faster than 92.21%
Memory Usage: 29.08 MB, less than 77.92%
Time complexity:
Space complexity:
Constraints:
    1 <= k, minLength <= s.length <= 1000
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def beautifulPartitions(self, s: str, k: int, minLength: int) -> int:
        mod, prime, sz, minLength = 10 ** 9 + 7, [2, 3, 5, 7], len(s), max(2, minLength)
        if minLength * k > sz:
            return 0
        prime_set, dp = set(prime), [[0 for _ in range(sz)] for _ in range(k + 1)]
        if int(s[0]) not in prime_set or int(s[-1]) in prime_set:
            return 0
        dp[0] = [1 for _ in range(sz)]
        if int(s[minLength - 1]) not in prime_set and int(s[minLength]) in prime_set:
            dp[1][minLength - 1] = 1
        for i in range(1, k):
            for j in range(minLength, sz - 1):
                dp[i][j] = dp[i][j - 1]
                if int(s[j]) not in prime_set and int(s[j + 1]) in prime_set:
                    dp[i][j] += dp[i - 1][j - minLength]
            dp[i][-1] = dp[i][-2] + dp[i - 1][-1 - minLength]

        return dp[k - 1][-1 - minLength] % mod


if __name__ == "__main__":
    s = Solution()
    string, k, minLength = "23542185131", 3, 2
    res = s.beautifulPartitions(string, k, minLength)
    print(res)
