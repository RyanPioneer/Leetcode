"""
Source: https://leetcode.com/problems/perfect-squares/
Date: 2022/11/22
Skill: Dynamic Programming
Runtime: 
Memory Usage: 
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List, Optional
import math

class Solution:
    def numSquares(self, n: int) -> int:
        dp = []
        for i in range(n+1):
            dp.append(i)
        i = 2
        while i*i <= n:
            j = i*i
            while j <= n:
                if dp[j-i*i]+1 < dp[j]:
                    dp[j] = dp[j-i*i]+1
                j = j+1
            i = i+1
        return dp[n]