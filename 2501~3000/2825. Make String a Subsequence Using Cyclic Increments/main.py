"""
Source: https://rb.gy/6l6nb
Date: 2023/8/20
Skill:
Runtime: 148 ms, faster than 80.00%
Memory Usage: 17.3 MB, less than 80.00%
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


class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        sz1, sz2 = len(str1), len(str2)
        if sz1 < sz2:
            return False
        left1, left2 = 0, 0
        while left1 < sz1 and left2 < sz2:
            if str1[left1] == str2[left2] or chr(ord(str1[left1]) + 1) == str2[left2] \
                    or (str1[left1] == "z" and str2[left2] == "a"):
                left2 += 1
            left1 += 1
        return left2 == sz2


if __name__ == "__main__":
    s = Solution()
