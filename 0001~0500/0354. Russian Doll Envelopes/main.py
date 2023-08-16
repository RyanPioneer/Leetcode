"""
Source: https://rb.gy/qt0o8
Date: 2023/8/16
Skill:
Ref:
Runtime: 1013 ms, faster than 86.71%
Memory Usage: 64.28 MB, less than 28.35%
Time complexity:
Space complexity:
Constraints:
    1 <= envelopes.length <= 10 ** 5
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: [x[0], -x[1]])
        sz = len(envelopes)
        dp = [sys.maxsize for _ in range(sz + 1)]
        dp[0], maxlen = -sys.maxsize, 0
        for i in range(sz):
            if envelopes[i][1] > dp[maxlen]:
                maxlen += 1
                dp[maxlen] = envelopes[i][1]
            else:
                pos = bisect_right(dp, envelopes[i][1])
                if pos <= maxlen and dp[pos - 1] < envelopes[i][1]:
                    dp[pos] = envelopes[i][1]
        return maxlen


if __name__ == "__main__":
    s = Solution()
    envelops = [[2, 100], [3, 200], [4, 300], [5, 500], [5, 400], [5, 250], [6, 370], [6, 360], [7, 380]]
    res = s.maxEnvelopes(envelops)
    print(res)
