"""
Source: https://leetcode.com/problems/distinct-subsequences-ii/
Date: 2023/3/27
Skill: Dynamic programming
Runtime: 151 ms, faster than 23.3%
Memory Usage: 13.9 MB, less than 45.45%
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
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10 ** 9 + 7
        dp = [0 for _ in range(26)]
        for c in s:
            nums = 1
            for i in range(26):
                nums += dp[i]
            dp[ord(c) - ord("a")] = nums

        return sum(dp) % MOD


if __name__ == "__main__":
    s = Solution()
