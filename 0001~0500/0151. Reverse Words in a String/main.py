"""
Source: https://rb.gy/guktk
Date: 2023/7/4
Skill:
Ref:
Runtime: 51 ms, faster than 46.67%
Memory Usage: 16.3 MB, less than 90.52%
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
    def reverseWords(self, s: str) -> str:
        res, idx = "", len(s) - 1
        while idx >= 0:
            while idx >= 0 and s[idx] == " ":
                idx -= 1
            if idx < 0:
                break
            string = ""
            while idx >= 0 and s[idx] != " ":
                string += s[idx]
                idx -= 1
            res += string[::-1] + " "
        return res[:-1]


if __name__ == "__main__":
    s = Solution()
