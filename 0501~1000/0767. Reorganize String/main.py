"""
Source: https://rb.gy/lwrve
Date: 2023/8/23
Skill:
Ref:
Runtime: 51 ms, faster than 33.47%
Memory Usage: 16.18 MB, less than 96.85%
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
        cnt, sz = Counter(s), len(s)
        res = ["" for _ in range(sz)]
        if cnt.most_common(1)[0][1] > (sz + 1) // 2:
            return ""
        num, pos, idx = 0, 0, 0
        while pos < sz:
            while pos < sz and num < cnt.most_common()[idx][1]:
                res[pos] = cnt.most_common()[idx][0]
                num += 1
                pos += 2
            if num == cnt.most_common()[idx][1]:
                idx += 1
                num = 0
        pos = 1
        while pos < sz:
            while num < cnt.most_common()[idx][1]:
                res[pos] = cnt.most_common()[idx][0]
                num += 1
                pos += 2
            if num == cnt.most_common()[idx][1]:
                idx += 1
                num = 0

        return "".join(res)


if __name__ == "__main__":
    s = Solution()
