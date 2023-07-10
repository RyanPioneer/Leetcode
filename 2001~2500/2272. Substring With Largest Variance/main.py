"""
Source: https://rb.gy/wr4a6
Date: 2023/7/9
Skill: Kadane
Ref: https://rb.gy/mp2vd
Runtime: 6788 ms, faster than 36.75%
Memory Usage: 16.4 MB, less than 87.18%
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
    def largestVariance(self, s: str) -> int:
        string_set, res = set(), 0
        for c in s:
            string_set.add(c)
        for c1 in string_set:
            for c2 in string_set:
                if c1 == c2:
                    continue
                sum0, sum1 = 0, -sys.maxsize
                for c in s:
                    if c == c1:
                        sum0 = sum0 + 1
                        sum1 = sum1 + 1
                    elif c == c2:
                        sum1 = max(sum1 - 1, sum0 - 1)
                        sum0 = 0
                    res = max(res, sum1)
        return res


if __name__ == "__main__":
    s = Solution()
