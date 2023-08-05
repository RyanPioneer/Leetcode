"""
Source: https://rb.gy/w0t0o
Date: 2023/8/4
Skill:
Ref:
Runtime: 652 ms, faster than 98.69%
Memory Usage: 36.58 MB, less than 25.98%
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
    def findArray(self, pref: List[int]) -> List[int]:
        res, sz = [pref[0]], len(pref)
        for i in range(1, sz):
            res.append(pref[i] ^ pref[i - 1])

        return res


if __name__ == "__main__":
    s = Solution()
