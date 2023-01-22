"""
Source: https://leetcode.com/problems/coin-change/description/
Date: 2023/1/22
Skill: Dynamic programming - Top down
Runtime: 1508 ms, faster than 74.15%
Memory Usage: 37.6 MB, less than 11.19%
Time complexity:
Space complexity:
Constraints:
    1 <= coins.length <= 12
"""

from typing import List
from collections import defaultdict
from functools import lru_cache

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        sz = len(coins)
        @lru_cache(None)

        def dfs(remainder):
            if remainder == 0:
                return 0
            if remainder < 0:
                return -1
            local_res = amount + 1
            for i in range(sz):
                next_res = dfs(remainder - coins[i])
                if next_res != -1:
                    local_res = min(local_res, next_res + 1)
            return local_res if local_res < amount + 1 else -1

        return dfs(amount)