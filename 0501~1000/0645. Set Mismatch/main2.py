"""
Source: https://leetcode.com/problems/set-mismatch/
Date: 2023/3/10
Skill:
Runtime: 380 ms, faster than 15.98%
Memory Usage: 15.9 MB, less than 19.22%
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
        s = len(nums) * (len(nums)+1) // 2
        a = sum(set(nums))
        b = sum(nums)
        return [b-a, s-a]


if __name__ == "__main__":
    s = Solution()
    nums = [3, 2, 2]
    res = s.findErrorNums(nums)
    print(res)
