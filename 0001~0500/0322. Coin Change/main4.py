"""
Source: https://leetcode.com/problems/coin-change/description/
Date: 2023/1/22
Skill: Dynamic programming - Bottom up
Runtime: 1436 ms, faster than 82.70%
Memory Usage: 14.3 MB, less than 59.79%
Time complexity:
Space complexity:
Constraints:
    1 <= coins.length <= 12
"""
import math
from typing import List
from collections import defaultdict
from functools import lru_cache

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [math.inf for _ in range(amount+1)]
        dp[0] = 0
        for coin in coins:
            for i in range(coin, amount+1):
                dp[i] = min(dp[i-coin]+1, dp[i])

        return dp[amount] if dp[amount] != math.inf else -1