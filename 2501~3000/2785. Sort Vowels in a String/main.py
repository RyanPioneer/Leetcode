"""
Source: https://rb.gy/qj3uj
Date: 2023/7/23
Skill:
Ref:
Runtime: 167 ms, faster than 80.00%
Memory Usage: 19.8 MB, less than 100.00%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def sortVowels(self, s: str) -> str:
        vowels, vowel_set, string, res = [], set(), "AEIOUaeiou", ""
        for c in string:
            vowel_set.add(c)
        for c in s:
            if c in vowel_set:
                vowels.append(c)

        vowels.sort(key=lambda x: ord(x), reverse=True)
        for c in s:
            if c in vowel_set:
                res += vowels.pop()
            else:
                res += c

        return res


if __name__ == "__main__":
    s = Solution()
