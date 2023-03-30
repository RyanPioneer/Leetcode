"""
Source: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
Date: 2023/3/30
Skill: Dynamic programming
Runtime: 51 ms, faster than 81.71%
Memory Usage: 14.2 MB, less than 29.27%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length, t.length <= 100
    s and t consist of lowercase English letters only.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        sz1, sz2, res = len(s), len(t), 0
        dp1, dp2 = [[0 for _ in range(sz2 + 1)] for _ in range(sz1 + 1)], \
            [[0 for _ in range(sz2 + 1)] for _ in range(sz1 + 1)]
        for i in range(1, sz1 + 1):
            for j in range(1, sz2 + 1):
                if s[i-1] == t[j-1]:
                    dp1[i][j] = dp1[i-1][j-1] + 1
                if s[sz1 - i] == t[sz2 - j]:
                    dp2[sz1 - i][sz2 - j] = dp2[sz1 - i + 1][sz2 - j + 1] + 1

        for i in range(sz1):
            for j in range(sz2):
                if s[i] != t[j]:
                    res += (1 + dp1[i][j]) * (1 + dp2[i + 1][j + 1])

        return res


if __name__ == "__main__":
    s = Solution()
