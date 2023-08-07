"""
Source: https://rb.gy/4cxpd
Date: 2023/8/7
Skill:
Ref:
Runtime: 38 ms, faster than 97.06%
Memory Usage: 16.3 MB, less than 77.98%
Time complexity:
Space complexity:
Constraints:
    1 <= num.length <= 3500
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def numberOfCombinations(self, num: str) -> int:
        mod, sz = 10 ** 9 + 7, len(num)
        if num[0] == "0":
            return 0



if __name__ == "__main__":
    s = Solution()
