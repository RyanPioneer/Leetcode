"""
Source: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
Date: 2023/4/1
Skill:
Runtime: 188 ms, faster than 52.23%
Memory Usage: 16.6 MB, less than 13.15%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10^5
    s consists of only lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def numSplits(self, s: str) -> int:
        dp1, dp2, sz = [0 for _ in range(len(s))], [0 for _ in range(len(s))], len(s)
        set1, set2, res = set(s[0]), set(s[sz - 1]), 0
        dp1[0], dp2[sz - 1] = 1, 1
        for i in range(1, sz):
            dp1[i], dp2[sz - i - 1] = dp1[i - 1], dp2[sz - i]
            if s[i] not in set1:
                set1.add(s[i])
                dp1[i] += 1
            if s[sz - i - 1] not in set2:
                set2.add(s[sz - i - 1])
                dp2[sz - i - 1] += 1

        for i in range(1, sz):
            if dp1[i - 1] == dp2[i]:
                res += 1

        return res


if __name__ == "__main__":
    s = Solution()
