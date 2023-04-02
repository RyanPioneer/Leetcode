"""
Source: https://leetcode.com/problems/maximum-score-from-removing-substrings/
Date: 2023/4/1
Skill:
Runtime: 1179 ms, faster than 10.10%
Memory Usage: 15.2 MB, less than 69.70%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10^5
    s consists of lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:  # "ab": x  "ba": y
        res, sz, string, string2 = 0, len(s), "", ""
        if x < y:
            s = s[::-1]
            x, y = y, x
        for i in range(sz):
            string += s[i]
            if len(string) >= 2 and string[-2:] == "ab":
                string = string[:-2]
                res += x

        sz = len(string)
        for i in range(sz):
            string2 += string[i]
            if len(string2) >= 2 and string2[-2:] == "ba":
                string2 = string2[:-2]
                res += y

        return res


if __name__ == "__main__":
    s = Solution()
