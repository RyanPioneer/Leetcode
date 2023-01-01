"""
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Date: 2022/12/23
Skill: 
Runtime: 72 ms, faster than 79.42% 
Memory Usage: 15.2 MB, less than 25.38%
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
        sz, valley, dir, index, res = len(prices), 0, 1, 0, 0
        while index+1 < sz:
            if prices[index] < prices[index+1] and dir == 1:
                valley, dir = prices[index], 0
            elif prices[index] > prices[index+1] and dir == 0:
                res += (prices[index]-valley)
                dir = 1
            
            index += 1
        
        if not dir: res += (prices[sz-1]-valley)
        return res
    
if __name__ == "__main__":
    s = Solution
    print(s.maxProfit(s, [7,1,5,3,6,4]))