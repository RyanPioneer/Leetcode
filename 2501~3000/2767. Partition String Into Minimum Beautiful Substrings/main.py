"""
Source: https://rb.gy/sset3
Date: 2023/7/18
Skill:
Ref:
Runtime: 57 ms, faster than 75.77%
Memory Usage: 16.4 MB, less than 74.45%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 15
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minimumBeautifulSubstrings(self, s: str) -> int:
        if s[0] == "0":
            return -1
        res, sz = 16, len(s)
        def dfs(idx, num):
            nonlocal res
            if idx == sz:
                res = min(res, num)
                return
            if s[idx] == "0":
                return
            cur_num = 0
            for i in range(idx, sz):
                cur_num *= 2
                cur_num += int(s[i])
                n = cur_num
                while n % 5 == 0:
                    n //= 5
                if n == 1:
                    dfs(i+1, num+1)

        dfs(0, 0)
        return -1 if res == 16 else res


if __name__ == "__main__":
    s = Solution()
