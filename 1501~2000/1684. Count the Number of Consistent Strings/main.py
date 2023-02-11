"""
Source: https://leetcode.com/problems/count-the-number-of-consistent-strings/
Date: 2023/2/11
Skill:
Runtime: 208 ms, faster than 99.29%
Memory Usage: 15.9 MB, less than 84.29%
Time complexity:
Space complexity:
Constraints:
    1 <= words.length <= 10^4
    The characters in allowed are distinct.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed, count = set(allowed), 0
        for word in words:
            for c in word:
                if c not in allowed:
                    count += 1
                    break

        return len(words) - count

if __name__ == "__main__":
    s = Solution