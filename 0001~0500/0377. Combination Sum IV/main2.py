"""
Source: https://leetcode.com/problems/combination-sum-iv/description/
Date: 2023/1/2
Skill: Recursion + Memorization
Runtime: 43 ms, faster than 83.22%
Memory Usage: 14 MB, less than 30.18%
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
        memo = [-1 for _ in range(target+1)]
        memo[0] = 1

        def dp(remainder):
            if remainder < 0: return 0
            if memo[remainder] != -1: return memo[remainder]
            ans = 0
            for num in nums:
                if num > remainder: break
                ans += dp(remainder-num)

            memo[remainder] = ans
            return memo[remainder]

        return dp(target)


if __name__ == "__main__":
    s = Solution