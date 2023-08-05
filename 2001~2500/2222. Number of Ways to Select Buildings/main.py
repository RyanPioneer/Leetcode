"""
Source: https://rb.gy/nmj5h
Date: 2023/8/5
Skill:
Ref:
Runtime: 819 ms, faster than 61.43%
Memory Usage: 17.66 MB, less than 36.00%
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
    def numberOfWays(self, s: str) -> int:
        dp, sz = [0 for _ in range(2)], len(s)
        dp2 = [[0 for _ in range(2)] for _ in range(2)]
        if s[0] == '0':
            dp2[0][0] = 1
        else:
            dp2[1][0] = 1
        for i in range(1, sz):
            if s[i] == "0":
                dp2[0][0] += 1
                dp2[0][1] += dp2[1][0]
                dp[0] = dp[0] + dp2[1][1]
            else:
                dp2[1][0] += 1
                dp2[1][1] += dp2[0][0]
                dp[1] = dp[1] + dp2[0][1]

        return sum(dp)


if __name__ == "__main__":
    s = Solution()
    string = "001101"
    res = s.numberOfWays(string)
