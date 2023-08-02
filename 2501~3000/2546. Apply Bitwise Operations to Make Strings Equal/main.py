"""
Source: https://rb.gy/219u8
Date: 2023/8/2
Skill:
Ref:
Runtime: 83 ms, faster than 27.85%
Memory Usage: 17.44 MB, less than 72.15%
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
    def makeStringsEqual(self, s: str, target: str) -> bool:
        s_one_num, target_one_num, sz = 0, 0, len(s)
        for i in range(sz):
            if s[i] == "1":
                s_one_num += 1
            if target[i] == "1":
                target_one_num += 1
        return (s_one_num == 0 and target_one_num == 0) or (s_one_num > 0 and target_one_num > 0)


if __name__ == "__main__":
    s = Solution