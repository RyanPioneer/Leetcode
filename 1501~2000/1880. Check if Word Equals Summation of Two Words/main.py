"""
Source: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/
Date: 2023/2/18
Skill:
Ref:
Runtime: 37 ms, faster than 40.7%
Memory Usage: 13.8 MB, less than 68.80%
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
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        key2value, num1, num2, num3 = defaultdict(int), "", "", ""
        for i in range(10):
            key2value[chr(ord("a")+i)] = i

        for c in firstWord:
            num1 += key2value[c]

        for c in secondWord:
            num2 += key2value[c]

        for c in targetWord:
            num3 += key2value[c]

        return int(num1) + int(num2) == int(num3)


if __name__ == "__main__":
    s = Solution