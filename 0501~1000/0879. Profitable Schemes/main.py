"""
Source: https://leetcode.com/problems/profitable-schemes/
Date: 2023/4/21
Skill:
Ref:
Runtime: 3335 ms, faster than 37.14%
Memory Usage: 46.4 MB, less than 41.90%
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
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        MOD, sz, res = 10 ** 9 + 7, len(group), 0 if minProfit > 0 else 1
        group.insert(0, 0)
        profit.insert(0, 0)
        dp = [[[0 for _ in range(minProfit + 1)] for _ in range(n + 1)] for _ in range(sz + 1)]
        dp[0][0][0] = 1
        for i in range(sz):
            for j in range(n + 1):
                for k in range(minProfit + 1):
                    dp[i + 1][j][k] += dp[i][j][k]
                    if j + group[i + 1] <= n:
                        dp[i + 1][j + group[i + 1]][min(minProfit, k + profit[i + 1])] += dp[i][j][k]

        for i in range(1, n + 1):
            res += dp[sz][i][minProfit]

        return res % MOD


if __name__ == "__main__":
    s = Solution()
    res = s.profitableSchemes(5, 3, [2, 2], [2, 3])
