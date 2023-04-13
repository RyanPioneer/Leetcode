"""
Source: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
Date: 2023/4/13
Skill:
Ref:
Runtime: 2123 ms, faster than 5.9%
Memory Usage: 19.9 MB, less than 15.85%
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
    def minimumDeletions(self, s: str) -> int:
        sz, res = len(s), 0
        pre, suf = [0 for _ in range(sz)], [0 for _ in range(sz)]
        if s[0] == "a":
            pre[0] = 1
        if s[sz - 1] == "b":
            suf[sz - 1] = 1
        for i in range(1, sz):
            pre[i], suf[sz - 1 - i] = pre[i - 1], suf[sz - i]
            if s[i] == "a":
                pre[i] += 1
            if s[sz - 1 - i] == "b":
                suf[sz - 1 - i] += 1

        res = max(pre[sz - 1], suf[0])
        for i in range(1, sz):
            res = max(res, pre[i - 1] + suf[i])

        return sz - res


if __name__ == "__main__":
    s = Solution()
