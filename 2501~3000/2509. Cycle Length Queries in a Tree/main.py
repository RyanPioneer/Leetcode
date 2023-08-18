"""
Source: https://rb.gy/gk3zh
Date: 2023/8/18
Skill:
Ref:
Runtime: 1051 ms, faster than 95.24%
Memory Usage: 56.11 MB, less than 10.48%
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
    def cycleLengthQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        res = []
        for query in queries:
            a, b, cnt = query[0], query[1], 0
            while a != b:
                if a < b:
                    b //= 2
                else:
                    a //= 2
                cnt += 1
            res.append(cnt + 1)
        return res


if __name__ == "__main__":
    s = Solution()
