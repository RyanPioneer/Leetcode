"""
Source: https://leetcode.com/problems/add-binary/
Date: 2023/1/23
Skill:
Runtime: 70 ms, faster than 14.97%
Memory Usage: 13.8 MB, less than 66.37%
Time complexity:
Space complexity:
Constraints:
    1 <= a.length, b.length <= 10^4
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools

class Solution:
    def addBinary(self, a: str, b: str) -> str:
            carry, res = 0, ""
            if len(a) < len(b): a, b = b, a
            for i in range(len(b)):
                if carry ^ (a[len(a)-i-1] == "1") ^ (b[len(b)-i-1] == "1"):
                    res += "1"
                else:
                    res += "0"
                carry = (carry and (a[len(a) - i - 1] == "1")) or (carry and (b[len(b) - i - 1] == "1")) or (
                            (a[len(a) - i - 1] == "1") and (b[len(b) - i - 1] == "1"))

            for i in range(len(b), len(a)):
                if carry ^ (a[len(a)-i-1] == "1"):
                    res += "1"
                else:
                    res += "0"
                carry = (carry and (a[len(a) - i - 1] == "1"))

            if carry: res += "1"
            return res[::-1]

if __name__ == "__main__":
    a, b = "1010", "1011"
    s = Solution
    res = s.addBinary(s, a, b)