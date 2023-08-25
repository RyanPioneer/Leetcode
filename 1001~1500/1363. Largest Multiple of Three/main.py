"""
Source: https://rb.gy/r97np
Date: 2023/8/24
Skill:
Runtime: 319 ms, faster than 8.45%
Memory Usage: 16.7 MB, less than 98.59%
Time complexity:
Space complexity:
Constraints:
    1 <= digits.length <= 10 ** 4
    0 <= digits[i] <= 9
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        digits.sort(reverse=True)
        digits.insert(0, 0)
        sz = len(digits)
        dp = ["", "#", "#"]
        for i in range(1, sz):
            dp2 = dp.copy()
            for j in range(3):
                if dp2[(j - digits[i] % 3 + 3) % 3] != "#" and (dp2[j] == "#" or len(dp2[(j - digits[i] % 3 + 3) % 3]) >= len(dp2[j])):
                    dp[j] = dp2[(j - digits[i] % 3 + 3) % 3] + str(digits[i])
                else:
                    dp[j] = dp2[j]

        return dp[0] if len(dp[0]) == 0 or dp[0][0] != "0" else "0"


if __name__ == "__main__":
    s = Solution()
