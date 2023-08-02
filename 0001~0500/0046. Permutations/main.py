"""
Source: https://rb.gy/swqo5
Date: 2023/8/2
Skill:
Ref:
Runtime: 47 ms, faster than 89.92%
Memory Usage: 16.64 MB, less than 13.68%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res, sz = [], len(nums)

        def helper(idx):
            if idx == sz:
                res.append(nums.copy())
                return
            for i in range(idx, sz):
                nums[idx], nums[i] = nums[i], nums[idx]
                helper(idx + 1)
                nums[idx], nums[i] = nums[i], nums[idx]

        helper(0)
        return res


if __name__ == "__main__":
    s = Solution()
