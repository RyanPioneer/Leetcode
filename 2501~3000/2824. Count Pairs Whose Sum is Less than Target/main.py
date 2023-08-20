"""
Source: https://rb.gy/ndrli
Date: 2023/8/20
Skill:
Runtime: 53 ms, faster than 100.00%
Memory Usage: 16.31 MB, less than 66.67%
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
    def countPairs(self, nums: List[int], target: int) -> int:
        res, sz = 0, len(nums)
        nums.sort()
        left, right = 0, sz - 1
        while left < right:
            while right > left and nums[left] + nums[right] >= target:
                right -= 1
            res += right - left
            left += 1
        return res


if __name__ == "__main__":
    s = Solution()
