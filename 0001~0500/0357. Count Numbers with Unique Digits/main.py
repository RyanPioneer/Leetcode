"""
Source: https://leetcode.com/problems/count-numbers-with-unique-digits/
Date: 2023/4/8
Skill:
Ref:
Runtime: 34 ms, faster than 48.66%
Memory Usage: 13.7 MB, less than 92.15%
Time complexity:
Space complexity:
Constraints:
    0 <= n <= 8
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        res = 1
        for i in range(n, 0, -1):
            num, digits = 9, 9
            for _ in range(i - 1):
                num *= digits
                digits -= 1
            res += num

        return res


if __name__ == "__main__":
    s = Solution()
