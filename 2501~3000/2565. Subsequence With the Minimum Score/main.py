"""
Source: https://rb.gy/dsev1
Date: 2023/7/31
Skill:
Ref:
Runtime: 147 ms, faster than 90.00%
Memory Usage: 22.25 MB, less than 32.50%
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
    def minimumScore(self, s: str, t: str) -> int:
        sz1, sz2 = len(s), len(t)
        left, right, idx1, idx2 = [sz1 for _ in range(sz2)], [-1 for _ in range(sz2)], 0, sz1 - 1
        for i in range(sz2):
            while idx1 < sz1 and s[idx1] != t[i]:
                idx1 += 1
            if idx1 < sz1:
                left[i] = idx1
                idx1 += 1
            while idx2 >= 0 and s[idx2] != t[sz2 - 1 - i]:
                idx2 -= 1
            if idx2 >= 0:
                right[sz2 - 1 - i] = idx2
                idx2 -= 1

        def check_feasible(length):
            if right[length] != -1 or left[sz2 - length - 1] != sz1:
                return True
            for i in range(1, sz2 - length):
                if left[i - 1] < right[i + length]:
                    return True
            return False

        lo, hi = 0, sz2
        while lo < hi:
            mid = (lo + hi) // 2
            if check_feasible(mid):
                hi = mid
            else:
                lo = mid + 1

        return lo


if __name__ == "__main__":
    s = Solution()
