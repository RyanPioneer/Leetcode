"""
Source: https://rb.gy/1yw8e
Date: 2023/7/26
Skill:
Ref:
Runtime: 127 ms, faster than 63.26%
Memory Usage: 16.6 MB, less than 60.34%
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
    def firstUniqChar(self, s: str) -> int:
        mydict, sz = defaultdict(int), len(s)
        for c in s:
            mydict[c] += 1
        for i in range(sz):
            if mydict[s[i]] == 1:
                return i
        return -1


if __name__ == "__main__":
    s = Solution()
