"""
Source: https://leetcode.com/problems/find-the-string-with-lcp/
Date: 2023/4/6
Skill:
Ref:
Runtime: 2132 ms, faster than 80.84%
Memory Usage: 75.4 MB, less than 50.41%
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


class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        s, pos, sz = [0 for _ in range(len(lcp))], 0, len(lcp)
        for i in range(ord('a'), ord('z') + 1):
            char = chr(i)
            while pos < sz and s[pos] != 0:
                pos += 1
            if pos == sz:
                break
            for j in range(sz):
                if lcp[pos][j] > 0:
                    s[j] = char

        for i in range(sz):
            if s[i] == 0:
                return ""
        dp = [[0 for _ in range(sz + 1)] for _ in range(sz + 1)]
        for i in range(sz - 1, -1, -1):
            for j in range(sz - 1, -1, -1):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j + 1] + 1
                if dp[i][j] != lcp[i][j]:
                    return ""

        return "".join(s)


if __name__ == "__main__":
    s = Solution()
    lcp = [[2, 0], [1, 1]]
    res = s.findTheString(lcp)
