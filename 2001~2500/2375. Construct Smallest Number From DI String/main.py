"""
Source: https://leetcode.com/problems/construct-smallest-number-from-di-string/
Date: 2023/8/5
Skill:
Ref:
Runtime: 40 ms, faster than 86.01%
Memory Usage: 16.4 MB, less than 18.53%
Time complexity:
Space complexity:
Constraints:
    1 <= pattern.length <= 8
    pattern consists of only the letters 'I' and 'D'.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def smallestNumber(self, pattern: str) -> str:
        pattern = "I" + pattern
        start, sz, res, idx, hi = 0, len(pattern), "", 0, 0
        while idx < sz:
            while idx + 1 < sz and pattern[idx + 1] == "I":
                start += 1
                res += chr(ord("0") + start)
                idx += 1
            num = 0
            while idx + 1 < sz and pattern[idx + 1] == "D":
                num += 1
                idx += 1
            start, hi = start + num + 1, start + num + 1
            res += chr(ord("0") + start)
            for _ in range(num):
                start -= 1
                res += chr(ord("0") + start)
            start = hi
            idx += 1

        return res


if __name__ == "__main__":
    s = Solution()
    pattern = "IIIDIDDD"
    res = s.smallestNumber(pattern)
    print(res)
