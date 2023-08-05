"""
Source: https://rb.gy/2tm2z
Date: 2023/8/4
Skill:
Ref:
Runtime: 1387 ms, faster than 64.76%
Memory Usage: 20.43 MB, less than 67.84%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res, sz = [], len(nums)
        for i in range(sz - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left, right = i + 1, sz - 1
            while left < right:
                if nums[left] + nums[right] == -nums[i]:
                    res.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                elif nums[left] + nums[right] > -nums[i]:
                    right -= 1
                else:
                    left += 1

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [3, 0, -2, -1, 1, 2]
    res = s.threeSum(nums)
