"""
Source: https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/
Date: 2023/2/18
Skill:
Runtime: 34 ms, faster than 95.78%
Memory Usage: 13.9 MB, less than 61.29%
Time complexity:
Space complexity:
Constraints:
    s.length == 5
    'A' <= s[0] <= s[3] <= 'Z'
    '1' <= s[1] <= s[4] <= '9'
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        res = []
        for i in range(ord(s[0]), ord(s[3])+1):
            for j in range(int(s[1]), int(s[4])+1):
                res.append(chr(i)+str(j)) # ord to char: chr(ord(c))

        return res


if __name__ == "__main__":
    s = Solution