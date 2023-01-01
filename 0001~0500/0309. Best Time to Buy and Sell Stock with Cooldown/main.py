"""
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
Date: 2022/12/23
Skill: Dynamic Programming, State Machine
Runtime: 53 ms, faster than 79.81% 
Memory Usage: 14.1 MB, less than 81.39%
Time complexity: 
Space complexity: 
Constraints: 
    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000
"""

from typing import List
import math

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [[0, 0, 0],[0, -math.inf, 0]] # Idle, Hold, Cooldown
        for price in prices:
            dp[0][0], dp[0][1], dp[0][2] = dp[1][0], dp[1][1], dp[1][2]
            dp[1][0] = max(dp[0][0], dp[0][2])
            dp[1][1] = max(dp[0][0]-price, dp[0][1])
            dp[1][2] = dp[0][1]+price
        
        return max(dp[1][0], dp[1][2])