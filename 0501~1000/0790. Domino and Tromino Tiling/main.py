"""
Source: https://leetcode.com/problems/domino-and-tromino-tiling/description/
Date: 2022/12/24
Skill: Dynamic Programming
Ref: https://leetcode.com/problems/domino-and-tromino-tiling/solutions/116581/detail-and-explanation-of-o-n-solution-why-dp-n-2-d-n-1-dp-n-3/?orderBy=most_votes
Runtime: 34 ms, faster than 94.76% 
Memory Usage: 13.9 MB, less than 85.40%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= n <= 1000
"""

from typing import List

class Solution:
    def numTilings(self, n: int) -> int:
        if n<2: return 1
        MOD = pow(10, 9)+7
        dp = [1 for i in range(n+1)]
        dp[2] = 2
        for i in range(3, n+1):
            dp[i] = (2*dp[i-1] + dp[i-3])%MOD
        
        return dp[n]