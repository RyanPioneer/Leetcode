"""
Source: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
Date: 2023/4/21
Skill:
Ref:
Runtime: 1643 ms, faster than 27.44%
Memory Usage: 28 MB, less than 86.73%
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
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        lo, hi, sz = min(bloomDay), max(bloomDay), len(bloomDay)
        if m * k > sz:
            return -1

        def check(day):
            cnt, num = 0 if bloomDay[0] > day else 1, 0
            if cnt == k:
                num = 1
                cnt = 0
            for i in range(1, sz):
                if num >= m:
                    return True
                if bloomDay[i] > day:
                    cnt = 0
                else:
                    if cnt == k - 1:
                        num += 1
                        cnt = 0
                    else:
                        cnt += 1

            return num >= m

        while lo < hi:
            mid = (lo + hi) // 2
            if check(mid):
                hi = mid
            else:
                lo = mid + 1

        return lo if check(lo) else -1


if __name__ == "__main__":
    s = Solution()
    res = s.minDays([97, 83], 2, 1)
