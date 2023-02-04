"""
Source: https://leetcode.com/problems/permutation-in-string/
Date: 2023/2/4
Skill:
Runtime: 73 ms, faster than 78.34%
Memory Usage: 14.1 MB, less than 28.54%
Time complexity:
Space complexity:
Constraints:
    1 <= s1.length, s2.length <= 10^4
    s1 and s2 consist of lowercase English letters.
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False
        nums, target, sz = [0 for _ in range(26)], [0 for _ in range(26)], len(s1)
        for i in range(sz):
            target[ord(s1[i]) - ord("a")] += 1
            nums[ord(s2[i]) - ord("a")] += 1

        if nums == target: return True
        for i in range(sz, len(s2)):
            nums[ord(s2[i-sz]) - ord("a")] -= 1
            nums[ord(s2[i]) - ord("a")] += 1
            if nums == target: return True

        return False