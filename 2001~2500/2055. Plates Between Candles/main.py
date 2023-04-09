"""
Source: https://leetcode.com/problems/plates-between-candles/
Date: 2023/4/9
Skill:
Ref:
Runtime: 2060 ms, faster than 55.40%
Memory Usage: 53.4 MB, less than 49.91%
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
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        presum, sz, res = [0 for _ in range(len(s))], len(s), []
        left_candle, right_candle = [-1 for _ in range(sz)], [sz for _ in range(sz)]
        if s[0] == "*":
            presum[0] = 1
        else:
            left_candle[0] = 0
        if s[sz - 1] == "|":
            right_candle[sz - 1] = sz - 1

        for i in range(1, sz):
            presum[i] = presum[i-1]
            if s[i] == "*":
                presum[i] += 1
                left_candle[i] = left_candle[i - 1]
            else:
                left_candle[i] = i
            if s[sz - i - 1] == "|":
                right_candle[sz - i - 1] = sz - i - 1
            else:
                right_candle[sz - i - 1] = right_candle[sz - i]

        for query in queries:
            left, right = right_candle[query[0]], left_candle[query[1]]
            if left >= query[1] - 1 or right <= query[0] + 1:
                res.append(0)
            else:
                res.append(presum[right] - presum[left])

        return res


if __name__ == "__main__":
    s = Solution()
