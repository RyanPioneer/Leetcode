"""
Source: https://rb.gy/4u16e
Date: 2023/8/13
Skill:
Runtime: 954 ms, faster than 80.00%
Memory Usage: 30.53 MB, less than 63.08%
Time complexity:
Space complexity:
Constraints:
    2 <= nums.length <= 10 ** 5
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        if len(nums) == 2:
            return nums[0] == nums[1]
        dp, sz = [0 for _ in range(len(nums))], len(nums)
        if nums[0] == nums[1]:
            dp[1] = 1
        if nums[0] == nums[1] == nums[2]:
            dp[2] = 1
        if nums[2] - nums[1] == nums[1] - nums[0] == 1:
            dp[2] = 1
        for i in range(3, sz):
            if nums[i] == nums[i - 1]:
                dp[i] = max(dp[i], dp[i - 2])
            if nums[i] == nums[i - 1] == nums[i - 2]:
                dp[i] = max(dp[i], dp[i - 3])
            if nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] == 1:
                dp[i] = max(dp[i], dp[i - 3])

        return dp[-1] == 1


if __name__ == "__main__":
    s = Solution()
