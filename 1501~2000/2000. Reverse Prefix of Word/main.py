"""
Source: https://leetcode.com/problems/reverse-prefix-of-word/
Date: 2023/2/18
Skill:
Runtime: 29 ms, faster than 81.91%
Memory Usage: 13.9 MB, less than 54.39%
Time complexity:
Space complexity:
Constraints:
    1 <= word.length <= 250
    word consists of lowercase English letters.
    ch is a lowercase English letter.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        sz = len(word)
        for i in range(sz):
            if word[i] == ch:
                return word[i::-1] + word[i+1:]

        return word


if __name__ == "__main__":
    s = Solution