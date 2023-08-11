"""
Source: https://rb.gy/395gs
Date: 2023/8/11
Skill:
Ref:
Runtime: 1903 ms, faster than 7.12%
Memory Usage: 18.32 MB, less than 61.12%
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
    def change(self, amount: int, coins: List[int]) -> int:
        dp, sz = [0 for _ in range(amount + 1)], len(coins)
        dp[0], visited_num = 1, set()
        visited_num.add(0)
        for i in range(sz):
            dp2 = dp.copy()
            num = coins[i]
            new_num_set = set()
            while num <= amount:
                for n in visited_num:
                    if num + n <= amount:
                        dp[num + n] += dp2[n]
                        new_num_set.add(n + num)
                num += coins[i]
            for n in new_num_set:
                visited_num.add(n)
        return dp[-1]


if __name__ == "__main__":
    s = Solution()
