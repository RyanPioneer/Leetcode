"""
Source: https://leetcode.com/problems/palindrome-partitioning-iv/
Date: 2023/4/13
Skill: Dynamic Programming
Ref:
Runtime: 4996 ms, faster than 31.65%
Memory Usage: 45.8 MB, less than 36.71%
Time complexity:
Space complexity:
Constraints:
    3 <= s.length <= 2000
    s consists only of lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def checkPartitioning(self, s: str) -> bool:
        dp, sz = [[False for _ in range(len(s))] for _ in range(len(s))], len(s)
        for i in range(sz):
            dp[i][i] = True
            if i < sz - 1 and s[i] == s[i + 1]:
                dp[i][i + 1] = True

        for length in range(3, sz + 1):
            for i in range(sz - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1]
                else:
                    dp[i][j] = False

        for i in range(1, sz - 1):
            for j in range(i + 1, sz):
                if dp[0][i - 1] and dp[i][j - 1] and dp[j][sz - 1]:
                    return True

        return False


if __name__ == "__main__":
    s = Solution()
