"""
Source: https://leetcode.com/problems/set-mismatch/
Date: 2023/3/10
Skill:
Runtime: 387 ms, faster than 15.98%
Memory Usage: 15.4 MB, less than 81.59%
Time complexity:
Space complexity:
Constraints:
    2 <= nums.length <= 10^4
"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        pos, sz = 0, len(nums)
        while pos < sz:
            if nums[pos] != pos+1 and nums[pos] != nums[nums[pos]-1]:
                tmp = nums[nums[pos] - 1]
                nums[nums[pos] - 1] = nums[pos]
                nums[pos] = tmp
                pos -= 1
            pos += 1

        for i in range(sz):
            if nums[i] != i+1:
                return [nums[i], i+1]


if __name__ == "__main__":
    s = Solution()
    nums = [3, 2, 2]
    res = s.findErrorNums(nums)
    print(res)
