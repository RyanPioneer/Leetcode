"""
Source: https://rb.gy/culyc
Date: 2023/8/20
Skill:
Runtime: 484 ms, faster than 80.61%
Memory Usage: 30.46 MB, less than 93.20%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10 ** 5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        nums.sort()
        pos1, pos2, sz, res = 0, 1, len(nums), 0
        while pos2 < sz:
            while pos2 < sz and nums[pos1] >= nums[pos2]:
                pos2 += 1
            if pos2 < sz:
                res += 1
            pos1 += 1
            pos2 += 1
        return res


if __name__ == "__main__":
    s = Solution()
