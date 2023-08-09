"""
Source: https://leetcode.com/problems/count-increasing-quadruplets/
Date: 2023/8/9
Skill:
Runtime: TLE
Memory Usage:
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
        sz, res = len(nums), 0
        smaller_before, bigger_after = [[0 for _ in range(sz + 1)] for _ in range(sz + 1)], [[0 for _ in range(sz + 1)] for _ in range(sz + 1)]
        for i in range(sz):
            for j in range(1, sz + 1):
                if nums[i] < j:
                    smaller_before[i + 1][j] = smaller_before[i][j] + 1
                else:
                    smaller_before[i + 1][j] = smaller_before[i][j]
                if nums[sz - 1 - i] > j:
                    bigger_after[sz - 1 - i][j] = bigger_after[sz - i][j] + 1
                else:
                    bigger_after[sz - 1 - i][j] = bigger_after[sz - i][j]

        for i in range(1, sz - 2):
            for j in range(i + 1, sz - 1):
                if nums[i] > nums[j]:
                    res += smaller_before[i][nums[j]] * bigger_after[j][nums[i]]
        return res


if __name__ == "__main__":
    s = Solution()
    nums = [1, 3, 5, 2, 4]
    res = s.countQuadruplets(nums)
    print(res)

