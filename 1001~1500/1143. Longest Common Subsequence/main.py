"""
Source: https://leetcode.com/problems/longest-common-subsequence/description/
Date: 2022/12/15
Skill:
Runtime: 423 ms, faster than 90.30% 
Memory Usage: 22 MB, less than 81.56%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.
"""

from typing import List, Optional

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0]*(len(text1)+1) for i in range(len(text2)+1)]
        for i in range (1, len(text2)+1):
            for j in range (1, len(text1)+1):
                if text2[i-1] == text1[j-1]:
                    dp[i][j] = dp[i-1][j-1]+1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[len(text2)+1][len(text1)+1]