"""
Source: https://rb.gy/sm242
Date: 2023/8/22
Skill:
Ref:
Runtime: 33 ms, faster than 90.97%
Memory Usage: 16.3 MB, less than 63.20%
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
from functools import cache


class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = ""
        while columnNumber > 26:
            res += chr(ord("A") + (columnNumber - 1) % 26)
            columnNumber = (columnNumber - 1) // 26
        res += chr(ord("A") + (columnNumber - 1) % 26)
        return res[::-1]


if __name__ == "__main__":
    s = Solution()
