"""
Source: https://leetcode.com/problems/count-pairs-of-similar-strings/
Date: 2023/2/11
Skill:
Runtime: 56 ms, faster than 97.38%
Memory Usage: 14.1 MB, less than 36.93%
Time complexity:
Space complexity:
Constraints:
    1 <= words.length <= 100
    words[i] consist of only lowercase English letters.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def similarPairs(self, words: List[str]) -> int:
        word_map, res = defaultdict(int), 0
        for word in words:
            cur = sorted(set(word))
            cur = "".join(cur)
            word_map[cur] += 1

        for key, value in word_map.items():
            if value > 1:
                res += value * (value-1) // 2

        return res

if __name__ == "__main__":
    s = Solution