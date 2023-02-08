"""
Source: https://leetcode.com/problems/house-robber-iv/
Date: 2023/2/8
Skill:
Runtime: 7859 ms, faster than 5.9%
Memory Usage: 30.8 MB, less than 6.85%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
    1 <= k <= (nums.length + 1)/2
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        sz = len(nums)
        def find_houses(cap) -> bool:
            dp = [[0 for _ in range(2)] for _ in range(sz)]
            dp[0][0], dp[0][1] = 0, 1 if nums[0] <= cap else 0
            for i in range(1, sz):
                dp[i][0] = max(dp[i - 1][1], dp[i - 1][0])
                dp[i][1] = dp[i - 1][0] + 1 if nums[i] <= cap else -math.inf

            return max(dp[sz-1][0], dp[sz-1][1]) >= k

        lower_bound, upper_bound = min(nums), max(nums)
        while lower_bound < upper_bound:
            mid = (lower_bound + upper_bound)//2
            if find_houses(mid):
                upper_bound = mid
            else:
                lower_bound = mid+1

        return upper_bound


if __name__ == "__main__":
    s = Solution
    nums, k = [2,7,9,3,1], 2
    res = s.minCapability(s, nums, k)