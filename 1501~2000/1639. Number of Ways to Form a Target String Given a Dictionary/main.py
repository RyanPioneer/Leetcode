"""
Source: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
Date: 2023/4/16
Skill:
Ref:
Runtime: 2939 ms, faster than 31.13%
Memory Usage: 292.3 MB, less than 22.18%
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
    def numWays(self, words: List[str], target: str) -> int:
        length, num, target_length, MOD = len(words[0]), len(words), len(target), 10 ** 9 + 7
        count = [[0 for _ in range(26)] for _ in range(length)]
        dp = [[0 for _ in range(target_length)] for _ in range(length)]
        for i in range(length):
            for j in range(num):
                count[i][ord(words[j][i]) - ord("a")] += 1

        dp[0][0] = count[0][ord(target[0]) - ord("a")]
        for i in range(1, length):
            dp[i][0] = dp[i - 1][0] + count[i][ord(target[0]) - ord("a")]

        for i in range(1, length):
            for j in range(1, target_length):
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * count[i][ord(target[j]) - ord("a")]

        return dp[length - 1][target_length - 1] % MOD


if __name__ == "__main__":
    s = Solution()
