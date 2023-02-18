"""
Source: https://leetcode.com/problems/counting-words-with-a-given-prefix/
Date: 2023/2/18
Skill:
Ref:
Runtime: 42 ms, faster than 65.50%
Memory Usage: 13.9 MB, less than 61.17%
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
    def prefixCount(self, words: List[str], pref: str) -> int:
        res, sz = 0, len(pref)
        for word in words:
            if len(word) >= sz and word[:sz] == pref:
                res += 1
        return res


if __name__ == "__main__":
    s = Solution