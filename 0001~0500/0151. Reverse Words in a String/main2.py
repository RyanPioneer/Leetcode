"""
Source: https://rb.gy/guktk
Date: 2023/7/4
Skill:
Ref:
Runtime: 43 ms, faster than 86.9%
Memory Usage: 16.4 MB, less than 90.52%
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
        return " ".join(reversed(s.split()))


if __name__ == "__main__":
    s = Solution()
