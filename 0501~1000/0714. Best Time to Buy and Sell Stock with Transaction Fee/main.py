"""
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
Date: 2022/12/23
Skill: Dynamic Programming 
Runtime: 992 ms, faster than 79.99% 
Memory Usage: 21 MB, less than 92.3%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List
import math

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        hold, sold = -math.inf, 0
        for price in prices:
            hold, sold = max(hold, sold-price), max(sold, hold+price-fee)
            
        return sold
    
if __name__ == "__main__":
    s = Solution
    print(s.maxProfit(s, [1,3,7,5,10,3], 3))