"""
Source: https://leetcode.com/problems/sort-an-array/
Date: 2023/3/1
Skill: Quick Sort
Ref:
Runtime: TLE
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 5 * 10^4
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        sz = len(nums)

        def quick_sort(l, r):
            if l >= r:
                return
            pivot_number, cur, left, right = nums[l], l, l, r
            while cur <= right:
                if nums[cur] < pivot_number:
                    nums[cur], nums[left] = nums[left], nums[cur]
                    cur += 1
                    left += 1
                elif nums[cur] > pivot_number:
                    nums[cur], nums[right] = nums[right], nums[cur]
                    right -= 1
                else:
                    cur += 1
            if left-1 > l:
                quick_sort(l, left-1)
            if right+1 < r:
                quick_sort(right+1, r)

        quick_sort(0, sz-1)
        return nums


if __name__ == "__main__":
    s = Solution