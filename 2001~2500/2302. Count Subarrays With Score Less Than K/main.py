"""
Source: https://rb.gy/w4mp5
Date: 2023/7/10
Skill:
Ref:
Runtime: 3397 ms, faster than 7.30%
Memory Usage: 31.2 MB, less than 8.38%
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
    def countSubarrays(self, nums: List[int], k: int) -> int:
        presum = [nums[i] for i in range(len(nums))]
        for i in range(1, len(nums)):
            presum[i] += presum[i - 1]
        nums.insert(0, sys.maxsize)
        presum.insert(0, 0)
        res, sz = 0, len(nums) - 1
        for i in range(1, sz + 1):
            left, right = 0, i
            while left < right:
                mid = (left + right) // 2
                if (presum[i] - presum[mid]) * (i - mid) >= k:
                    left = mid + 1
                else:
                    right = mid
            res += i - right
        return res


if __name__ == "__main__":
    s = Solution()
    nums, k = [1, 1, 1], 5
    res = s.countSubarrays(nums, k)
