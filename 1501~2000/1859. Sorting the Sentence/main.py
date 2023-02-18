"""
Source: https://leetcode.com/problems/sorting-the-sentence/
Date: 2023/2/17
Skill:
Runtime: 29 ms, faster than 80.65%
Memory Usage: 13.9 MB, less than 49.23%
Time complexity:
Space complexity:
Constraints:
    The number of words in s is between 1 and 9.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split(" ")
        res = [None for _ in range(len(words))]
        for word in words:
            res[int(word[-1])-1] = word[:-1]

        return " ".join(res)


if __name__ == "__main__":
    s = Solution