"""
Source: https://leetcode.com/problems/find-the-duplicate-number/
Date: 2023/3/10
Skill: Cycle Sort
Ref: https://www.geeksforgeeks.org/cycle-sort/
Runtime: 711 ms, faster than 25.14%
Memory Usage: 27.9 MB, less than 87.72%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 10^5
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
    def findDuplicate(self, nums: List[int]) -> int:
        sz, pos = len(nums), 0
        while pos < sz:
            if nums[pos] != pos+1:
                if nums[nums[pos]-1] == nums[pos]:
                    return nums[pos]
                nums[nums[pos]-1], nums[pos] = nums[pos], nums[nums[pos]-1]
            else:
                pos += 1

        for i in range(sz):
            if nums[i] != i+1:
                return nums[i]

        return -1


if __name__ == "__main__":
    s = Solution()
