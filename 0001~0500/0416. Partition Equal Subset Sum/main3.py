"""
Source: https://leetcode.com/problems/partition-equal-subset-sum/
Date: 2023/8/22
Skill:
Runtime: 642 ms, faster than 72.62%
Memory Usage: 156.16 MB, less than 11.72%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 100
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total, sz = sum(nums), len(nums)
        if total % 2 == 1:
            return False

        @cache
        def dfs(idx, rem):
            if rem == 0:
                return True
            if idx == sz:
                return rem == 0
            if nums[idx] <= rem and dfs(idx + 1, rem - nums[idx]):
                return True
            if dfs(idx + 1, rem):
                return True
            return False

        return dfs(0, total // 2)


if __name__ == "__main__":
    s = Solution()
    nums = [14, 9, 8, 4, 3, 2]
    res = s.canPartition(nums)
