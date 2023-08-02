"""
Source: https://rb.gy/nfkog
Date: 2023/8/2
Skill: Longest Common Subsequence
Ref:
Runtime: 9834 ms, faster than 5.19%
Memory Usage: 527.2 MB, less than 9.09%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def deleteString(self, s: str) -> int:
        s_set = set(s)
        if len(s_set) == 1:
            return len(s)
        dp, sz = [1 for _ in range(len(s) + 1)], len(s)
        lcs = [[0 for _ in range(sz + 1)] for _ in range(sz + 1)]

        for i in range(sz - 1, -1, -1):
            for j in range(sz - 1, -1, -1):
                if s[i] == s[j]:
                    lcs[i][j] = lcs[i + 1][j + 1] + 1

        for i in range(sz - 1, -1, -1):
            for j in range(i + 1, sz):
                if lcs[i][j] >= j - i:
                    dp[i] = max(dp[i], dp[j] + 1)

        return dp[0]


if __name__ == "__main__":
    s = Solution()
