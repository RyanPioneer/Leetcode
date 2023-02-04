"""
Source: https://leetcode.com/problems/verifying-an-alien-dictionary/
Date: 2023/2/2
Skill:
Runtime: 32 ms, faster than 93.63%
Memory Usage: 13.9 MB, less than 31.27%
Time complexity:
Space complexity:
Constraints:
    1 <= words.length <= 100
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        my_map = {}
        for index, char in enumerate(order):
            my_map[char] = index

        for i in range(len(words) - 1):
            for j in range(len(words[i])):
                if j >= len(words[i + 1]):
                    return False
                if words[i][j] != words[i + 1][j]:
                    if my_map[words[i][j]] > my_map[words[i + 1][j]]:
                        return False
                    else:
                        break

        return True