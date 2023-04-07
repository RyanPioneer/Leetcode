"""
Source: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
Date: 2023/4/7
Skill:
Ref:
Runtime: 1119 ms, faster than 23.50%
Memory Usage: 37.8 MB, less than 9.77%
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
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        myset, mymap, sz = set(), defaultdict(int), len(nums)
        for i in range(sz):
            nums[i] %= value
            if nums[i] not in mymap:
                mymap[nums[i]] = nums[i]
            else:
                mymap[nums[i]] += value
            myset.add(mymap[nums[i]])
        i = 0
        while True:
            if i not in myset:
                return i
            i += 1


if __name__ == "__main__":
    s = Solution()
    nums = [1, -10, 7, 13, 6, 8]
    value = 5
    res = s.findSmallestInteger(nums, value)
