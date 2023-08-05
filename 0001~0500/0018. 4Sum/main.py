"""
Source: https://rb.gy/l5ky9
Date: 2023/8/4
Skill:
Ref:
Runtime: 801 ms, faster than 67.85%
Memory Usage: 16.3 MB, less than 91.70%
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
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res, sz = [], len(nums)
        for i in range(sz - 3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i + 1, sz - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                left, right, cur_sum = j + 1, sz - 1, nums[i] + nums[j]
                while left < right:
                    if nums[left] + nums[right] + cur_sum == target:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        left += 1
                        right -= 1
                        while left < right and nums[left] == nums[left - 1]:
                            left += 1
                        while left < right and nums[right] == nums[right + 1]:
                            right -= 1
                    elif nums[left] + nums[right] + cur_sum < target:
                        left += 1
                    else:
                        right -= 1

        return res


if __name__ == "__main__":
    s = Solution()
