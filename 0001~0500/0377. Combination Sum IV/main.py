"""
Source: https://leetcode.com/problems/combination-sum-iv/description/
Date: 2023/1/2
Skill: Dynamic Programming
Runtime: 40 ms, faster than 90.7%
Memory Usage: 13.9 MB, less than 79.87%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 1000
    All the elements of nums are unique.
"""

from typing import List

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        nums.sort()
        dp = [0 for _ in range(target+1)]
        dp[0] = 1

        for i in range(1, target + 1):
            for num in nums:
                if num > i: break
                dp[i] += dp[i-num]

        return dp[target]

if __name__ == "__main__":
    s = Solution