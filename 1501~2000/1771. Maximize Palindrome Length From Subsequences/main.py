"""
Source: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
Date: 2023/4/13
Skill:
Ref:
Runtime: 2371 ms, faster than 58.33%
Memory Usage: 67.8 MB, less than 55.56%
Time complexity:
Space complexity:
Constraints:
    1 <= word1.length, word2.length <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def longestPalindrome(self, word1: str, word2: str) -> int:
        sz1, sz2, res = len(word1), len(word2), 0
        word, sz = word1 + word2, sz1 + sz2
        dp = [[0 for _ in range(sz)] for _ in range(sz)]
        for i in range(sz):
            dp[i][i] = 1

        for length in range(2, sz + 1):
            for i in range(sz - length + 1):
                j = i + length - 1
                if word[i] == word[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                    if i < sz1 <= j:
                        res = max(res, dp[i][j])
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

        return res


if __name__ == "__main__":
    s = Solution()
