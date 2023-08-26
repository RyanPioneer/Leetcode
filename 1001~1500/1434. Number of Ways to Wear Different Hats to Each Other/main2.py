"""
Source: https://rb.gy/msko7
Date: 2023/8/26
Skill:
Runtime: 302 ms, faster than 72.66%
Memory Usage: 47.39 MB, less than 9.38%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 10
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        n, mod, hat2people = len(hats), 10 ** 9 + 7, defaultdict(list)
        for i in range(n):
            for hat in hats[i]:
                hat2people[hat].append(i)

        state = (1 << n) - 1

        @cache
        def dfs(idx, cur_state):
            if cur_state == 0:
                return 1
            if idx == 41:
                return 0
            res = dfs(idx + 1, cur_state)
            for i in hat2people[idx]:
                num = 1 << i
                if cur_state & num != 0:
                    res += dfs(idx + 1, cur_state - num) % mod

            return res % mod

        return dfs(0, state)


if __name__ == "__main__":
    s = Solution()
    hats = [[3, 4], [4, 5], [5]]
    res = s.numberWays(hats)
    print(res)
