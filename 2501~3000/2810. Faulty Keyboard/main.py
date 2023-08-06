"""
Source: https://rb.gy/8ch49
Date: 2023/8/6
Skill:
Ref:
Runtime: 43 ms, faster than 100.00%
Memory Usage: 16.2 MB, less than 93.83%
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
    def finalString(self, s: str) -> str:
        res = ""
        for c in s:
            if c != "i":
                res += c
            else:
                res = res[::-1]
        return res


if __name__ == "__main__":
    s = Solution()
