"""
Source: https://rb.gy/ahzvz
Date: 2023/7/30
Skill: 
Ref:
Runtime: 321 ms, faster than 97.32%
Memory Usage: 54.86 MB, less than 13.22%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        str1, str2 = "#" + str1, "#" + str2
        sz1, sz2 = len(str1), len(str2)
        dp = [[sys.maxsize for _ in range(sz2)] for _ in range(sz1)]
        for i in range(sz1):
            dp[i][0] = i + 1
        for i in range(sz2):
            dp[0][i] = i + 1
        for i in range(1, sz1):
            for j in range(1, sz2):
                if str1[i] == str2[j]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1

        idx1, idx2, res = sz1 - 1, sz2 - 1, ""
        while idx1 >= 1 and idx2 >= 1:
            if str1[idx1] == str2[idx2]:
                res = str1[idx1] + res
                idx1 -= 1
                idx2 -= 1
            elif dp[idx1][idx2] == dp[idx1 - 1][idx2] + 1:
                res = str1[idx1] + res
                idx1 -= 1
            else:
                res = str2[idx2] + res
                idx2 -= 1

        while idx1 >= 1:
            res = str1[idx1] + res
            idx1 -= 1

        while idx2 >= 1:
            res = str2[idx2] + res
            idx2 -= 1

        return res


if __name__ == "__main__":
    s = Solution()
