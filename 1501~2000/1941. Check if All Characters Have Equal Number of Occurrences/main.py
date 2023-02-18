"""
Source: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
Date: 2023/2/18
Skill:
Ref:
Runtime: 30 ms, faster than 91.43%
Memory Usage: 13.8 MB, less than 96.83%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 1000
    s consists of lowercase English letters.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        my_dict = defaultdict(int)
        for c in s:
            my_dict[c] += 1

        num = my_dict[s[0]]
        for key, value in my_dict.items():
            if value != num:
                return False

        return True


if __name__ == "__main__":
    s = Solution