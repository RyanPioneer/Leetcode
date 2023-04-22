"""
Source: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/
Date: 2023/4/22
Skill:
Ref:
Runtime: 50 ms, faster than 46.84%
Memory Usage: 14.6 MB, less than 43.4%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 2 * 10^9
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minDays(self, n: int) -> int:
        dp = defaultdict(int)
        dp[0], dp[1] = 0, 1

        def count(num):
            if num in dp:
                return dp[num]
            dp[num] = 1 + min(num % 2 + count(num // 2), num % 3 + count(num // 3))
            return dp[num]

        return count(n)


if __name__ == "__main__":
    s = Solution()
