"""
Source: https://leetcode.com/problems/shortest-distance-to-a-character/description/
Date: 2023/2/18
Skill:
Ref:
Runtime: 46 ms, faster than 66.67%
Memory Usage: 14 MB, less than 49.36%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10^4
    s[i] and c are lowercase English letters.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        res, prev, sz = [], -math.inf, len(s)
        for i in range(sz):
            if s[i] == c:
                prev = i
            res.append(i-prev)

        prev = math.inf
        for i in range(sz-1, -1, -1):
            if s[i] == c:
                prev = i
            res[i] = min(res[i], prev-i)

        return res


if __name__ == "__main__":
    s = Solution