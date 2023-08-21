"""
Source: https://rb.gy/55ys2
Date: 2023/8/21
Skill:
Ref:
Runtime: 416 ms, faster than 90.73%
Memory Usage: 18.63 MB, less than 7.30%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 500
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
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        res = [["" for _ in range(m)] for _ in range(n)]



if __name__ == "__main__":
    s = Solution()
