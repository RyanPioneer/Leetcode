"""
Source: https://leetcode.com/problems/delete-and-earn/
Date: 2023/1/4
Skill:
Runtime: 120 ms, faster than 61.11%
Memory Usage: 15.9 MB, less than 75.39%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 2 * 10^4
    1 <= nums[i] <= 10^4
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        dict = defaultdict(int)
        for num in nums:
            dict[num] += num

        myKeys = list(dict.keys())
        myKeys.sort()
        dp = [0, dict[myKeys[0]]]
        for i in range(1, len(myKeys)):
            if myKeys[i] - myKeys[i-1] == 1:
                dp[0], dp[1] = max(dp[0], dp[1]), dp[0]+dict[myKeys[i]]
            else:
                dp[0], dp[1] = max(dp[0], dp[1]), max(dp[0], dp[1]) + dict[myKeys[i]]

        return max(dp[0], dp[1])

if __name__ == "__main__":
    s = Solution