"""
Source: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
Date: 2023/4/21
Skill:
Ref:
Runtime: 974 ms, faster than 72.70%
Memory Usage: 14.2 MB, less than 87.3%
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
from bisect import bisect_left, bisect_right


class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.insert(0, 0)
        cuts.append(n)
        cuts.sort()
        sz = len(cuts)
        dp = [[math.inf for _ in range(sz)] for _ in range(sz)]
        for i in range(sz - 1):
            dp[i][i + 1] = 0
        for length in range(2, sz):
            for i in range(sz - length):
                j = i + length
                for k in range(i + 1, j):
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j])

        return dp[0][sz - 1]


if __name__ == "__main__":
    s = Solution()
