"""
Source: https://rb.gy/lwrve
Date: 2023/8/23
Skill:
Ref:
Runtime: 46 ms, faster than 55.06%
Memory Usage: 16.16 MB, less than 96.85%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 500
    s consists of lowercase English letters.
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
    def reorganizeString(self, s: str) -> str:
        cnt, sz, res, heap = Counter(s), len(s), "", []
        heapify(heap)
        for key, val in cnt.items():
            heappush(heap, [-val, key])
        for i in range(0, sz, 2):
            freq, val = heappop(heap)
            res += val
            if i < sz - 1:
                if not heap:
                    return ""
                freq2, val2 = heappop(heap)
                res += val2
                if freq2 + 1 < 0:
                    heappush(heap, [freq2 + 1, val2])
            if freq + 1 < 0:
                heappush(heap, [freq + 1, val])
        return res


if __name__ == "__main__":
    s = Solution()
