"""
Source: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
Date: 2023/3/4
Skill:
Runtime: 162 ms, faster than 35.15%
Memory Usage: 14.9 MB, less than 90.37%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        left, right, sz = nums[1] - nums[0], nums[len(nums) - 1] - nums[0], len(nums)
        for i in range(2, sz):
            left = min(left, nums[i] - nums[i-1])

        while left < right:
            mid, cnt = (left + right) // 2, 0
            for i in range(0, sz-1):
                pos = bisect_right(nums, nums[i] + mid)
                cnt += (pos - i - 1)

            if cnt < k:
                left = mid + 1
            else:
                right = mid

        return left


if __name__ == "__main__":
    s = Solution()
    nums, k = [1, 6, 1], 3
    res = s.smallestDistancePair(nums, k)
