"""
Source: https://leetcode.com/problems/add-strings/
Date: 2023/2/15
Skill:
Runtime: 42 ms, faster than 57.46%
Memory Usage: 14 MB, less than 47.87%
Time complexity:
Space complexity:
Constraints:
    1 <= num1.length, num2.length <= 10^4
    num1 and num2 consist of only digits.
    num1 and num2 don't have any leading zeros except for the zero itself.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        if len(num1) < len(num2):
            num1, num2 = num2, num1
        len1, len2, carry, res, cur = len(num1), len(num2), 0, "", 0
        for i in range(len2):
            carry += int(num1[len1 - i - 1]) + int(num2[len2 - i - 1])
            res += str(carry % 10)
            carry //= 10

        for i in range(len2, len1):
            carry += int(num1[len1 - i - 1])
            res += str(carry % 10)
            carry //= 10

        while carry > 0:
            res += str(carry % 10)
            carry //= 10

        return res[::-1]


if __name__ == "__main__":
    s = Solution