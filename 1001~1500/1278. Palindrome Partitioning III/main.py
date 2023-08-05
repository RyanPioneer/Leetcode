"""
Source: https://rb.gy/0zaky
Date: 2023/8/4
Skill:
Ref:
Runtime: 562 ms, faster than 13.53%
Memory Usage: 16.82 MB, less than 40.57%
Time complexity:
Space complexity:
Constraints:

"""

import math
import sys
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        dp, sz = [[sys.maxsize // 2 for _ in range(k + 1)] for _ in range(len(s))], len(s)
        dp[0][1] = 0
        for i in range(1, sz):
            left, right, num = 0, i, 0
            while left < right:
                if s[left] != s[right]:
                    num += 1
                left += 1
                right -= 1
            dp[i][1] = num
        for i in range(1, sz):
            for j in range(2, k + 1):
                if j > i + 1:
                    break
                for l in range(i, j - 2, -1):
                    left, right, num = l, i, 0
                    while left < right:
                        if s[left] != s[right]:
                            num += 1
                        left += 1
                        right -= 1
                    dp[i][j] = min(dp[i][j], dp[l - 1][j - 1] + num)

        return dp[-1][k]


if __name__ == "__main__":
    s = Solution()
