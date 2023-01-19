"""
Source: https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/
Date: 2023/1/18
Skill: Dynamic Programming
Ref:
Runtime: 1224 ms, faster than 87.65%
Memory Usage: 28.5 MB, less than 64.57%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        dp = [0, 0] # odd, even
        for num in nums:
            dp[0], dp[1] = max(dp[1]+num, dp[0]), max(dp[0]-num, dp[1])

        return dp[0]