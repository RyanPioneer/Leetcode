"""
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Date: 2022/12/23
Skill: 
Runtime: 58 ms, faster than 97.55% 
Memory Usage: 15.2 MB, less than 69.49%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= prices.length <= 3 * 10^4
    0 <= prices[i] <= 10^4
"""

from typing import List
import math

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                res += prices[i] - prices[i - 1]
        return res