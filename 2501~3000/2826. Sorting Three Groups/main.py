"""
Source: https://rb.gy/qqtl6
Date: 2023/8/20
Skill:
Runtime: 183 ms, faster than 100.00%
Memory Usage: 16.38 MB, less than 100.00%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 100
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        dp, sz = [[0 for _ in range(3)] for _ in range(len(nums))], len(nums)
        if nums[0] == 1:
            dp[0][1], dp[0][2] = 1, 1
        elif nums[0] == 2:
            dp[0][0], dp[0][2] = 1, 1
        else:
            dp[0][0], dp[0][1] = 1, 1
        for i in range(1, sz):
            if nums[i] == 1:
                dp[i][0], dp[i][1] = dp[i - 1][0], min(dp[i - 1][0], dp[i - 1][1]) + 1
                dp[i][2] = min(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1
            elif nums[i] == 2:
                dp[i][0], dp[i][1] = dp[i - 1][0] + 1, min(dp[i - 1][0], dp[i - 1][1])
                dp[i][2] = min(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1
            else:
                dp[i][0], dp[i][1] = dp[i - 1][0] + 1, min(dp[i - 1][0], dp[i - 1][1]) + 1
                dp[i][2] = min(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2])
        return min(dp[-1])


if __name__ == "__main__":
    s = Solution()
