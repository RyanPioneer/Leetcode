"""
Source: https://rb.gy/ni6jf
Date: 2023/7/18
Skill:
Ref:
Runtime: 617 ms, faster than 10.29%
Memory Usage: 29.75 MB, less than 37.75%
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
    def maximumGroups(self, grades: List[int]) -> int:
        if len(grades) <= 2:
            return 1
        grades.sort()
        cur_size, prev_size, sz = 0, 1, len(grades)
        for i in range(1, sz):
            cur_size += 1
            if cur_size == prev_size + 1:
                if sz - i - 1 > cur_size:
                    prev_size = cur_size
                    cur_size = 0
                else:
                    return cur_size


if __name__ == "__main__":
    s = Solution()
