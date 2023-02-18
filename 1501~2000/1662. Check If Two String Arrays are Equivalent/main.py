"""
Source: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
Date: 2023/2/17
Skill:
Runtime: 31 ms, faster than 83.43%
Memory Usage: 13.8 MB, less than 66.57%
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
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        s1, s2 = "", ""
        for word in word1:
            s1 += word
        for word in word2:
            s2 += word
        return s1 == s2


if __name__ == "__main__":
    s = Solution