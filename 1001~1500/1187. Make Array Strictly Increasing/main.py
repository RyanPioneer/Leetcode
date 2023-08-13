"""
Source: https://rb.gy/szw9q
Date: 2023/8/13
Skill:
Ref:
Runtime: 772 ms, faster than 55.49%
Memory Usage: 48.14 MB, less than 53.64%
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
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2.sort()
        arr1.insert(0, -1)
        sz1, sz2 = len(arr1), len(arr2)
        dp = [[sys.maxsize for _ in range(sz1)] for _ in range(sz1)]
        dp[0][0] = -1
        for i in range(1, sz1):
            for j in range(i + 1):
                if dp[i - 1][j] < arr1[i]:
                    dp[i][j] = min(dp[i][j], arr1[i])
                if j > 0:
                    pos = bisect_right(arr2, dp[i - 1][j - 1])
                    if pos < sz2:
                        dp[i][j] = min(dp[i][j], arr2[pos])

        for i in range(sz1):
            if dp[-1][i] != sys.maxsize:
                return i
        return -1


if __name__ == "__main__":
    s = Solution()

