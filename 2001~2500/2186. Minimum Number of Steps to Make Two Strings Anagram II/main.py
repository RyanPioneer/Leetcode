"""
Source: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
Date: 2023/7/3
Skill:
Ref:
Runtime: 506 ms, faster than 32.57%
Memory Usage: 18.7 MB, less than 57.20%
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
        s_count, res = defaultdict(int), len(s) + len(t)
        for c in s:
            s_count[c] += 1
        for c in t:
            if c in s_count and s_count[c] > 0:
                s_count[c] -= 1
                res -= 2
        return res


if __name__ == "__main__":
    s = Solution()
