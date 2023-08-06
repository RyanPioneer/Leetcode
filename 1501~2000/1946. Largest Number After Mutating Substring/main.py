"""
Source: https://rb.gy/74c68
Date: 2023/8/6
Skill:
Ref:
Runtime: 169 ms, faster than 93.18%
Memory Usage: 17.97 MB, less than 77.27%
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
    def maximumNumber(self, num: str, change: List[int]) -> str:
        idx, sz, res = 0, len(num), ""
        while idx < sz:
            digit = ord(num[idx]) - ord("0")
            if digit < change[digit]:
                break
            res += num[idx]
            idx += 1
        while idx < sz:
            digit = ord(num[idx]) - ord("0")
            if digit <= change[digit]:
                res += str(change[digit])
                idx += 1
            else:
                break
        return res + num[idx:]


if __name__ == "__main__":
    s = Solution()
