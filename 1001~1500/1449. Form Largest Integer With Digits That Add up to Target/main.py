"""
Source: https://rb.gy/p1pg2
Date: 2023/8/11
Skill:
Ref:
Runtime: 204 ms, faster than 72.97%
Memory Usage: 29.03 MB, less than 60.81%
Time complexity:
Space complexity:
Constraints:
    cost.length == 9
    1 <= cost[i], target <= 5000
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        dp, min_val = ["" for _ in range(target + 1)], min(cost)
        cost.insert(0, 0)
        for i in range(1, target + 1):
            dp[i] = "0"
            for j in range(1, 10):
                if i < cost[j] or dp[i - cost[j]] == "0":
                    continue
                cur_str = dp[i - cost[j]] + str(j)
                if len(cur_str) > len(dp[i]) or (len(cur_str) == len(dp[i]) and cur_str > dp[i]):
                    dp[i] = cur_str

        return dp[-1]


if __name__ == "__main__":
    s = Solution()
    cost, target = [2, 4, 6, 2, 4, 6, 4, 4, 4], 5
    res = s.largestNumber(cost, target)
    print(res)
