"""
Source: https://leetcode.com/problems/optimal-partition-of-string/
Date: 2023/4/4
Skill:
Runtime: 97 ms, faster than 92.74%
Memory Usage: 14.6 MB, less than 47.10%
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
    def partitionString(self, s: str) -> int:
        res, myset = 1, set()
        for c in s:
            if c in myset:
                res += 1
                myset.clear()
            myset.add(c)
        return res


if __name__ == "__main__":
    s = Solution()
