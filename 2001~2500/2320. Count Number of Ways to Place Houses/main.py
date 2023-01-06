"""
Source: https://leetcode.com/problems/count-number-of-ways-to-place-houses/
Date: 2023/1/4
Skill:
Runtime: 361 ms, faster than 51.19%
Memory Usage: 13.8 MB, less than 82.46%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 10^4
"""

from typing import List, Optional
from collections import defaultdict, Counter


class Solution:
    def countHousePlacements(self, n: int) -> int:
        dp, MOD = [1, 1], pow(10, 9) + 7
        for i in range(n - 1):
            dp[0], dp[1] = dp[0] + dp[1], dp[0]

        return pow(sum(dp), 2) % MOD

if __name__ == "__main__":
    s = Solution