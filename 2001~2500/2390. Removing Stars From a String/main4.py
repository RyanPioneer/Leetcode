"""
Source: https://leetcode.com/problems/removing-stars-from-a-string/
Date: 2023/4/11
Skill:
Ref:
Runtime: 224 ms, faster than 77.42%
Memory Usage: 15.7 MB, less than 40.9%
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
    def removeStars(self, s: str) -> str:
        res = []
        for c in s:
            if c == "*":
                res.pop()
            else:
                res.append(c)

        return "".join(res)


if __name__ == "__main__":
    s = Solution()
