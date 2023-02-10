"""
Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
Date: 2023/2/10
Skill: Quickselect
Runtime: 3305 ms, faster than 5.1%
Memory Usage: 37.8 MB, less than 6.77%
Time complexity:
Space complexity:
Constraints:
    1 <= k <= nums.length <= 10^5
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        def quick_select(l, u, t):
            lb, ub, p, pivot = l, u, l, nums[l]
            while p <= ub:
                if nums[p] < pivot:
                    nums[p], nums[lb] = nums[lb], nums[p]
                    lb += 1
                elif nums[p] > pivot:
                    nums[p], nums[ub] = nums[ub], nums[p]
                    ub -= 1
                else:
                    p += 1

            if lb - l >= t:
                return quick_select(l, lb-1, t)
            elif p - l >= t:
                return pivot
            else:
                return quick_select(p, u, t-(p-l))

        return quick_select(0, len(nums)-1, len(nums)-k+1)


if __name__ == "__main__":
    s = Solution