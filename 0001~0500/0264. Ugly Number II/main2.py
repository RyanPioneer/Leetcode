"""
Source: https://rb.gy/gcssw
Date: 2023/7/17
Skill:
Ref:
Runtime: 250 ms, faster than 23.60%
Memory Usage: 16.36 MB, less than 69.27%
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
    def nthUglyNumber(self, n: int) -> int:
        res, i, j, k = [1], 0, 0, 0
        while len(res) < n:
            num1, num2, num3 = res[i] * 2, res[j] * 3, res[k] * 5
            minimum = min(num1, num2, num3)
            if minimum == num1:
                i += 1
            elif minimum == num2:
                j += 1
            else:
                k += 1

            if minimum > res[-1]:
                res.append(minimum)

        return res[-1]


if __name__ == "__main__":
    s = Solution()
