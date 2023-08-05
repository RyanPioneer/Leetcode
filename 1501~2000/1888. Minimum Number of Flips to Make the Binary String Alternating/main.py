"""
Source: https://rb.gy/uut8x
Date: 2023/8/5
Skill:
Ref:
Runtime: 476 ms, faster than 87.67%
Memory Usage: 28.31 MB, less than 5.25%
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
    def minFlips(self, s: str) -> int:
        left01, left10, right01, right10 = [], [], [], []
        cnt1, cnt2, sz = 0, 0, len(s)
        for i in range(sz):
            if i % 2 == 0:
                if s[i] == "1":
                    cnt1 += 1
                else:
                    cnt2 += 1
            else:
                if s[i] == "0":
                    cnt1 += 1
                else:
                    cnt2 += 1
            left01.append(cnt1)
            left10.append(cnt2)

        cnt1, cnt2 = 0, 0
        for i in range(sz - 1, -1, -1):
            if (sz - 1 - i) % 2 == 0:
                if s[i] == "1":
                    cnt1 += 1
                else:
                    cnt2 += 1
            else:
                if s[i] == "0":
                    cnt1 += 1
                else:
                    cnt2 += 1
            right01.append(cnt1)
            right10.append(cnt2)

        right01.reverse()
        right10.reverse()
        res = min(left01[-1], left10[-1])
        for i in range(sz - 1):
            res = min(res, left01[i] + right10[i + 1], left10[i] + right01[i + 1])
        return res


if __name__ == "__main__":
    s = Solution()
    string = "111000"
    res = s.minFlips(string)
    print(res)
