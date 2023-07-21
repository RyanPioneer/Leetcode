"""
Source: https://rb.gy/ftxv2
Date: 2023/7/21
Skill: dp更新過程為何從現在推到未來？因為無法窮舉之前的可能
Ref:
Runtime: 7402 ms, faster than 5.07%
Memory Usage: 24.87 MB, less than 62.98%
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
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        cost.insert(0, 0)
        time.insert(0, 0)
        sz, offset, res = len(cost), len(cost) + 1, sys.maxsize
        dp = [[sys.maxsize for _ in range(2 * offset)] for _ in range(sz)]
        dp[0][offset] = 0
        for i in range(0, sz - 1):
            for j in range(-sz, sz + 1):
                dp[i + 1][j - 1 + offset] = min(dp[i + 1][j - 1 + offset], dp[i][j + offset])
                jj = min(j + time[i + 1], sz)
                dp[i + 1][jj + offset] = min(dp[i + 1][jj + offset], dp[i][j + offset] + cost[i + 1])

        for i in range(sz + 1):
            res = min(res, dp[-1][offset + i])

        return res


if __name__ == "__main__":
    s = Solution()
