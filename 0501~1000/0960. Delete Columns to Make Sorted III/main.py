"""
Source: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
Date: 2023/4/15
Skill: Dynamic Programming
Ref:
Runtime: 152 ms, faster than 89.6%
Memory Usage: 14 MB, less than 34.38%
Time complexity:
Space complexity:
Constraints:
    1 <= strs.length <= 100
    1 <= strs[i].length <= 100
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        num, length = len(strs), len(strs[0])
        dp = [1 for _ in range(length)]

        def check_available(i, j):
            for k in range(num):
                if strs[k][i] > strs[k][j]:
                    return False
            return True

        for i in range(1, length):
            for j in range(i):
                if check_available(j, i):
                    dp[i] = max(dp[i], dp[j] + 1)

        return length - max(dp)


if __name__ == "__main__":
    s = Solution()
