"""
Source: https://rb.gy/isi1d
Date: 2023/8/4
Skill:
Ref:
Runtime: 791 ms, faster than 25.77%
Memory Usage: 677.67 MB, less than 27.53%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        dp, mod = [0 for _ in range(high + 1)], 10 ** 9 + 7
        dp[0] = 1
        for i in range(high):
            if i + zero <= high:
                dp[i + zero] += dp[i]
            if i + one <= high:
                dp[i + one] += dp[i]

        return sum(dp[low: high + 1]) % mod


if __name__ == "__main__":
    s = Solution()
