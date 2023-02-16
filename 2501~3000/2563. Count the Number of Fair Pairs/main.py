"""
Source: https://leetcode.com/problems/count-the-number-of-fair-pairs/
Date: 2023/2/16
Skill:
Runtime: 915 ms, faster than 56.39%
Memory Usage: 29 MB, less than 26.7%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        res, sz = 0, len(nums)
        for i in range(sz):
            left, right = bisect.bisect_left(nums, lower - nums[i]), bisect.bisect_right(nums, upper - nums[i])
            res += right - left
            if left <= i and i < right: res -= 1

        return res // 2


if __name__ == "__main__":
    s = Solution
    nums, lower, upper = [1,7,9,2,5], 11, 11
    res = s.countFairPairs(s, nums, lower, upper)
    print(res)