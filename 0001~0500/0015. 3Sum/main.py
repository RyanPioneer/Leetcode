"""
Source: https://rb.gy/2tm2z
Date: 2023/8/4
Skill:
Ref:
Runtime: 2165 ms, faster than 34.79%
Memory Usage: 22.27 MB, less than 5.81%
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
        res, num_set, sz, ans_set = [], set(), len(nums), set()
        num_set.add(nums[0])
        for i in range(1, sz - 1):
            for j in range(i + 1, sz):
                if nums[0] + nums[i] + nums[j] > 0:
                    break
                if -(nums[i] + nums[j]) in num_set and (nums[i], nums[j]) not in ans_set:
                    ans_set.add((nums[i], nums[j]))
                    res.append([-(nums[i] + nums[j]), nums[i], nums[j]])
            num_set.add(nums[i])
        return res


if __name__ == "__main__":
    s = Solution()
    nums = [3, 0, -2, -1, 1, 2]
    res = s.threeSum(nums)
