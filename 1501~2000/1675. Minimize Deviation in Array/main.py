"""
Source: https://leetcode.com/problems/minimize-deviation-in-array/
Date: 2023/2/24
Skill:
Ref:
Runtime: 5645 ms, faster than 14.93%
Memory Usage: 22.5 MB, less than 47.76%
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
    def minimumDeviation(self, nums: List[int]) -> int:
        from sortedcontainers import SortedList
        for i in range(len(nums)):
            if nums[i] % 2 != 0:
                nums[i] *= 2

        nums, res = SortedList(nums), math.inf
        while True:
            min_value, max_value = nums[0], nums[-1]
            res = min(res, max_value - min_value)
            if max_value % 2 != 0:
                break
            nums.pop()
            nums.add(max_value // 2)

        return res


if __name__ == "__main__":
    s = Solution