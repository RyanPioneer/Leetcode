"""
Source: https://leetcode.com/problems/longest-ideal-subsequence/
Date: 2023/1/20
Skill:
Ref:
Runtime: Time Limit Exceeded
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10^5
"""

from typing import List, Optional

class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        dp, sz = [1 for _ in range(len(s))], len(s)
        for i in range(1, sz):
            for j in range(i):
                if abs(ord(s[i]) - ord(s[j])) <= k:
                    dp[i] = max(dp[i], dp[j]+1)

        return max(dp)

if __name__ == "__main__":
    string, k = "acfgbd", 2
    s = Solution
    print(s.longestIdealString(s, string, k))