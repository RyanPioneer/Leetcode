"""
Source: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/
Date: 2023/3/27
Skill:
Runtime: 688 ms, faster than 39.48%
Memory Usage: 28.8 MB, less than 35.27%
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
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        nums.sort()
        i, j, sz, res = 0, len(nums) // 2, len(nums), 0
        while i < sz // 2 and j < sz:
            while j + 1 < sz and nums[i] * 2 > nums[j]:
                j += 1
            if nums[i] * 2 <= nums[j]:
                res += 2
            i += 1
            j += 1

        return res


if __name__ == "__main__":
    s = Solution()
