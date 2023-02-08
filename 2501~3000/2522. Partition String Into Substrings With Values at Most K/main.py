"""
Source: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/
Date: 2023/2/8
Skill: Dynamic Programming
Runtime: 186 ms, faster than 67.96%
Memory Usage: 18.7 MB, less than 13.99%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10^5
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def minimumPartition(self, s: str, k: int) -> int:
        dp, sz = [1 for _ in range(len(s) + 1)], len(s)
        bit, dp[0] = len(str(k)), 0
        if bit == 1:
            for i in range(sz):
                if int(s[i]) > k:
                    return -1
            return sz

        for i in range(bit, sz + 1):
            if int(s[i-bit: i]) <= k:
                dp[i] = dp[i-bit]+1
            else:
                dp[i] = dp[i-bit+1]+1

        return dp[sz]


if __name__ == "__main__":
    s = Solution
    res = s.minimumPartition(s, "1829727651", 10)