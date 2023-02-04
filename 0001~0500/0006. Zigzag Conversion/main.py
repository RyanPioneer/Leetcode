"""
Source: https://leetcode.com/problems/zigzag-conversion/description/
Date: 2023/2/3
Skill:
Runtime: 51 ms, faster than 92.82%
Memory Usage: 13.9 MB, less than 94.57%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if len(s) <= numRows or numRows == 1: return s
        res, sz = "", len(s)
        for i in range(numRows):
            index, up, down, di = i, i*2, (numRows-i-1)*2, 0
            while index < sz:
                di = (di+1)%2
                res += s[index]
                if i == 0 or i == numRows-1:
                    index += 2*(numRows-1)
                else:
                    if di: index += down
                    else: index += up

        return res

if __name__ == "__main__":
    s = Solution
    res = s.convert(s, "PAYPALISHIRING", 4)