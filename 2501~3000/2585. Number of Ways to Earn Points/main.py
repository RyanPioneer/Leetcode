"""
Source: https://rb.gy/kip6s
Date: 2023/8/2
Skill:
Ref:
Runtime: 1391 ms, faster than 90.34%
Memory Usage: 16.42 MB, less than 77.84%
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
    def waysToReachTarget(self, target: int, types: List[List[int]]) -> int:
        dp, sz, MOD = [0 for _ in range(target + 1)], len(types), 10 ** 9 + 7
        dp[0] = 1
        for i in range(sz):
            dp1 = dp.copy()
            num, cnt = types[i][1], types[i][0]
            for j in range(target):
                if dp1[j] == 0:
                    continue
                cur_num = num
                for k in range(cnt):
                    if cur_num + j > target:
                        break
                    dp[j + cur_num] += dp1[j]
                    cur_num += num

        return dp[target] % MOD


if __name__ == "__main__":
    s = Solution()
