"""
Source: https://rb.gy/zrewl
Date: 2023/7/18
Skill:
Ref:
Runtime: 490 ms, faster than 57.86%
Memory Usage: 17.45 MB, less than 53.81%
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
    def longestContinuousSubstring(self, s: str) -> int:
        res, cur, sz = 1, 1, len(s)
        for i in range(1, sz):
            if ord(s[i]) == ord(s[i-1])+1:
                cur += 1
            else:
                res = max(res, cur)
                cur = 1

        return max(res, cur)


if __name__ == "__main__":
    s = Solution()
