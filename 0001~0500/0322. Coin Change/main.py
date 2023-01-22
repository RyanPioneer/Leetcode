"""
Source: https://leetcode.com/problems/coin-change/description/
Date: 2023/1/22
Skill: DFS
Runtime: Time Limit Exceeded
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    1 <= coins.length <= 12
"""

from typing import List
import math

from functools import lru_cache

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        sz = len(coins)
        def dfs(index, remainder):
            if remainder == 0: return 0
            elif index == sz: return -1
            local_res = amount+1
            for i in range(remainder//coins[index]+1):
                next_res = dfs(index+1, remainder-i*coins[index])
                if next_res != -1:
                    local_res = min(local_res, next_res+i)
            return local_res if local_res < amount+1 else -1

        return dfs(0, amount)

if __name__ == '__main__':
    s = Solution
    coins, amount = [1,2,5], 11
    res = s.coinChange(s, coins, amount)
    print(res)