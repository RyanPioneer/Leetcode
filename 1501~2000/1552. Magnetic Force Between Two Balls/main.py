"""
Source: https://leetcode.com/problems/magnetic-force-between-two-balls/
Date: 2023/4/21
Skill:
Ref:
Runtime: 1827 ms, faster than 14.33%
Memory Usage: 27.9 MB, less than 28.37%
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
from bisect import bisect_left, bisect_right


class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        lo, hi, sz = 1, position[-1] - position[0], len(position)

        def check(dis):
            nonlocal sz
            num, pos, prev = 1, 1, position[0]
            while pos < sz and num < m:
                if position[pos] - prev >= dis:
                    num += 1
                    prev = position[pos]
                pos += 1
            return num == m

        while lo < hi:
            mid = (hi + lo + 1) // 2
            if check(mid):
                lo = mid
            else:
                hi = mid - 1

        return lo


if __name__ == "__main__":
    s = Solution()
