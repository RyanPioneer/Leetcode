"""
Source: https://rb.gy/oac43
Date: 2023/8/3
Skill:
Ref:
Runtime: 40 ms, faster than 82.54%
Memory Usage: 16.34 MB, less than 49.91%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        if tx == sx and ty == sy:
            return True
        elif tx < sx or ty < sy:
            return False
        elif tx == sx:
            return (ty - sy) % sx == 0
        elif ty == sy:
            return (tx - sx) % sy == 0
        elif tx > ty:
            return self.reachingPoints(sx, sy, tx % ty, ty)
        elif tx < ty:
            return self.reachingPoints(sx, sy, tx, ty % tx)
        else:
            return False


if __name__ == "__main__":
    s = Solution()
    res = s.reachingPoints(1, 1, 3, 5)
