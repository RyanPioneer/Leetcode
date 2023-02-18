"""
Source: https://leetcode.com/problems/first-letter-to-appear-twice/
Date: 2023/2/18
Skill:
Ref:
Runtime: 32 ms, faster than 65.87%
Memory Usage: 13.7 MB, less than 94.27%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def repeatedCharacter(self, s: str) -> str:
        counter = defaultdict(int)
        for c in s:
            counter[c] += 1
            if counter[c] == 2:
                return c


if __name__ == "__main__":
    s = Solution