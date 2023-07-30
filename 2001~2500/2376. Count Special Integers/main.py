"""
Source: https://rb.gy/l0aac
Date: 2023/7/30
Skill:
Ref:
Runtime: 37 ms, faster than 97.79%
Memory Usage: 16.23 MB, less than 91.18%
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
    def countSpecialNumbers(self, n: int) -> int:
        s, res = str(n), 0

        def permutation(length, digits):
            num = 1
            for _ in range(length):
                num *= digits
                digits -= 1
            return num

        for i in range(1, len(s)):
            res += permutation(i, 10) - permutation(i - 1, 9)

        visited, sz = [0 for _ in range(10)], len(s)

        def dfs(idx):
            nonlocal res
            if idx == sz:
                res += 1
                return
            for i in range(10):
                if idx == 0 and i == 0:
                    continue
                if visited[i] or i > ord(s[idx]) - ord("0"):
                    continue
                elif i == ord(s[idx]) - ord("0"):
                    visited[i] = 1
                    dfs(idx + 1)
                    visited[i] = 0
                else:
                    res += permutation(sz - idx - 1, 10 - idx - 1)

        dfs(0)
        return res


if __name__ == "__main__":
    s = Solution()
