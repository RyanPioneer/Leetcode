"""
Source: https://leetcode.com/problems/count-increasing-quadruplets/
Date: 2023/8/9
Skill:
Ref: https://rb.gy/sw3cc
Runtime: 2771 ms, faster than 90.82%
Memory Usage: 16.73 MB, less than 95.08%
Time complexity:
Space complexity:
Constraints:
    4 <= nums.length <= 4000
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        sz, dp, res = len(nums), [0 for _ in range(len(nums))], 0
        for i in range(sz):
            prev_smaller = 0
            for j in range(i):
                if nums[i] > nums[j]:
                    prev_smaller += 1
                    res += dp[j]
                elif nums[i] < nums[j]:
                    dp[j] += prev_smaller
        return res


if __name__ == "__main__":
    s = Solution()
    nums = [1, 3, 5, 2, 4]
    res = s.countQuadruplets(nums)
    print(res)

