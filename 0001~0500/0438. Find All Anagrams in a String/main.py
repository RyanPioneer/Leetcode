"""
Source: https://leetcode.com/problems/find-all-anagrams-in-a-string/
Date: 2023/1/27
Skill: Sliding Window
Runtime: 106 ms, faster than 91.92%
Memory Usage: 15.3 MB, less than 28.13%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length, p.length <= 3 * 10^4
    s and p consist of lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p): return []
        words, cur_words, res, sz = [0 for _ in range(26)], [0 for _ in range(26)], [], len(p)
        for i in range(sz):
            words[ord(p[i]) - ord("a")] += 1
            cur_words[ord(s[i]) - ord("a")] += 1

        if cur_words == words: res.append(0)

        for i in range(sz, len(s)):
            cur_words[ord(s[i - sz]) - ord("a")] -= 1
            cur_words[ord(s[i]) - ord("a")] += 1
            if cur_words == words: res.append(i - sz + 1)

        return res