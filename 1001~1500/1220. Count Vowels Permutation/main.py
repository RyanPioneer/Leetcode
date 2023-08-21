"""
Source: https://rb.gy/orxun
Date: 2023/8/21
Skill:
Ref:
Runtime: 843 ms, faster than 19.54%
Memory Usage: 184.97 MB, less than 7.33%
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
from functools import cache


class Solution:
    def countVowelPermutation(self, n: int) -> int:
        mod, relation = 10 ** 9 + 7, {(0, 1), (1, 0), (1, 2), (2, 0), (2, 1), (2, 3), (2, 4), (3, 2), (3, 4), (4, 0)}

        @cache
        def dfs(prev, length):
            if length == 0:
                return 1
            num = 0
            for i in range(5):
                if (prev, i) in relation:
                    num += dfs(i, length - 1) % mod
                    num %= mod
            return num % mod

        res = 0
        for i in range(5):
            res += dfs(i, n - 1) % mod
            res %= mod
        return res


if __name__ == "__main__":
    s = Solution()
