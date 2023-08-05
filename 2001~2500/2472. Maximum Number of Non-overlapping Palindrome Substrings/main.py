"""
Source: https://rb.gy/v8xbt
Date: 2023/8/4
Skill:
Ref:
Runtime: 4408 ms, faster than 10.90%
Memory Usage: 48.14 MB, less than 13.53%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        sz = len(s)
        is_palindrome, dp = [[False for _ in range(sz)] for _ in range(sz)], [0 for _ in range(sz)]
        for i in range(sz):
            is_palindrome[i][i] = True
        for i in range(sz - 1):
            if s[i] == s[i + 1]:
                is_palindrome[i][i + 1] = True
        for length in range(3, sz + 1):
            for i in range(sz - length + 1):
                if s[i] == s[i + length - 1]:
                    is_palindrome[i][i + length - 1] = is_palindrome[i + 1][i + length - 2]

        for i in range(k - 1, sz):
            if i > 0:
                dp[i] = dp[i - 1]
            for length in range(k, i + 2):
                if is_palindrome[i - length + 1][i]:
                    if i - length + 1 == 0:
                        dp[i] = max(dp[i], 1)
                    else:
                        dp[i] = max(dp[i], dp[i - length] + 1)

        return dp[-1]


if __name__ == "__main__":
    s = Solution()
