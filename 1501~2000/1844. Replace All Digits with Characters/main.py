"""
Source: https://leetcode.com/problems/replace-all-digits-with-characters/
Date: 2023/2/18
Skill:
Runtime: 29 ms, faster than 84.66%
Memory Usage: 13.8 MB, less than 94.18%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 100
    s consists only of lowercase English letters and digits.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def replaceDigits(self, s: str) -> str:
        sz, res = len(s), ""
        for i in range(sz):
            if i%2 == 0:
                res += s[i]
            else:
                res += chr(ord(s[i-1]) + int(s[i]))

        return res


if __name__ == "__main__":
    s = Solution