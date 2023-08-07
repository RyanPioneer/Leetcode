"""
Source: https://rb.gy/n6v8q
Date: 2023/8/7
Skill:
Ref:
Runtime: 942 ms, faster than 84.80%
Memory Usage: 31.28 MB, less than 97.06%
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
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        monotonic_stack, res, sz = [], [], len(heights)
        for i in range(sz - 1, -1, -1):
            num = 0
            while monotonic_stack and heights[monotonic_stack[-1]] < heights[i]:
                monotonic_stack.pop()
                num += 1
            if len(monotonic_stack) >= 1:
                num += 1
            res.append(num)
            monotonic_stack.append(i)
        return reversed(res)


if __name__ == "__main__":
    s = Solution()
