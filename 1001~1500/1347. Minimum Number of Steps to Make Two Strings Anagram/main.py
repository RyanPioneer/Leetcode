"""
Source: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
Date: 2023/7/3
Skill:
Ref:
Runtime: 264 ms, faster than 38.43%
Memory Usage: 16.9 MB, less than 94.91%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minSteps(self, s: str, t: str) -> int:
        t_count, res = defaultdict(int), 0
        for i in range(len(s)):
            t_count[t[i]] += 1
        for c in s:
            if c in t_count and t_count[c] > 0:
                t_count[c] -= 1
            else:
                res += 1
        return res


if __name__ == "__main__":
    s = Solution()
