"""
Source: https://leetcode.com/problems/maximum-length-of-pair-chain/description/
Date: 2023/1/20
Skill: Dynamic Programming
Ref:
Runtime: 2544 ms, faster than 22.48%
Memory Usage: 14.3 MB, less than 77.37%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key = lambda x: x[0])
        dp = [1 for _ in range(len(pairs))]
        for i in range(len(pairs)):
            for j in range(i):
                if pairs[j][1] < pairs[i][0]:
                    dp[i] = max(dp[i], dp[j]+1)

        return max(dp)