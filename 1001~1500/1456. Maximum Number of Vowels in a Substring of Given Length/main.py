"""
Source: https://rb.gy/84mve
Date: 2023/7/18
Skill:
Ref:
Runtime: 151 ms, faster than 89.05%
Memory Usage: 17.08 MB, less than 98.77%
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
    def maxVowels(self, s: str, k: int) -> int:
        vowels, res, cur_num, sz = set(), 0, 0, len(s)
        for c in "aeiou":
            vowels.add(c)
        for i in range(k):
            if s[i] in vowels:
                cur_num += 1

        res = cur_num
        for i in range(sz - k):
            if s[i] in vowels:
                cur_num -= 1
            if s[i+k] in vowels:
                cur_num += 1
            res = max(res, cur_num)
        return res


if __name__ == "__main__":
    s = Solution()
