"""
Source: https://rb.gy/xfuum
Date: 2023/7/26
Skill:
Ref:
Runtime: 57 ms, faster than 91.32%
Memory Usage: 16.46 MB, less than 75.00%
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
    def lastStoneWeightII(self, stones: List[int]) -> int:
        myset, res = set(), sum(stones)
        myset.add(0)
        for stone in stones:
            set_temp = myset.copy()
            myset.clear()
            for s in set_temp:
                myset.add(s + stone)
                myset.add(s - stone)

        for num in myset:
            if 0 <= num < res:
                res = num

        return res


if __name__ == "__main__":
    s = Solution()
