"""
Source: https://leetcode.com/problems/longest-ideal-subsequence/
Date: 2023/1/20
Skill: Dynamic programming
Ref:
Runtime: 2639 ms, faster than 36.42%
Memory Usage: 14.6 MB, less than 96.69%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10^5
"""

from typing import List, Optional

class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        dp, sz = [0 for _ in range(26)], len(s)
        for i in range(sz):
            local_res = 0
            for j in range(max(ord(s[i])-ord("a")-k, 0), min(ord(s[i])-ord("a")+k+1, 26)):
                if dp[j] != 0:
                    local_res = max(local_res, dp[j]+1)
            dp[ord(s[i])-ord("a")] = max(1, local_res)

        return max(dp)

if __name__ == "__main__":
    string, k = "azaza", 25
    s = Solution
    print(s.longestIdealString(s, string, k))