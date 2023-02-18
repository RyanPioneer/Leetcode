"""
Source: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
Date: 2023/2/18
Skill:
Runtime: 29 ms, faster than 96.71%
Memory Usage: 13.9 MB, less than 69.75%
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
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        res = 0
        for pattern in patterns:
            if pattern in word:
                res += 1

        return res



if __name__ == "__main__":
    s = Solution