"""
Source: https://leetcode.com/problems/minimum-cost-to-split-an-array/
Date: 2023/3/29
Skill:
Runtime: 4832 ms, faster than 77.84%
Memory Usage: 14.1 MB, less than 82.34%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minCost(self, nums: List[int], k: int) -> int:
        dp, sz = [math.inf for _ in range(len(nums))], len(nums)
        for i in range(sz):
            my_map, importance = defaultdict(int), k
            for j in range(i, 0, -1):
                my_map[nums[j]] += 1
                if my_map[nums[j]] > 1:
                    if my_map[nums[j]] == 2:
                        importance += 1
                    importance += 1
                dp[i] = min(dp[j - 1] + importance, dp[i])
            my_map[nums[0]] += 1
            if my_map[nums[0]] > 1:
                if my_map[nums[0]] == 2:
                    importance += 1
                importance += 1
            dp[i] = min(importance, dp[i])

        return dp[sz - 1]


if __name__ == "__main__":
    s = Solution()
    nums = [1, 2, 1, 2, 1, 3, 3]
    k = 2
    res = s.minCost(nums, k)
