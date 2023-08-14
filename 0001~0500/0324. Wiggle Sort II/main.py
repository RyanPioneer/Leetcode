"""
Source: https://rb.gy/loj3h
Date: 2023/8/14
Skill:
Ref: https://rb.gy/ujlk3
Runtime: 570 ms, faster than 48.08%
Memory Usage: 27.07 MB, less than 81.07%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        def quick_select(left, right, idx):
            if left == right:
                return nums[left]
            pivot, l, r, pos = nums[left], left, right, left
            while pos <= r:
                if nums[pos] < pivot:
                    nums[pos], nums[l] = nums[l], nums[pos]
                    l += 1
                    pos += 1
                elif nums[pos] > pivot:
                    nums[pos], nums[r] = nums[r], nums[pos]
                    r -= 1
                else:
                    pos += 1
            if idx <= l - left:
                return quick_select(left, l - 1, idx)
            elif idx <= r - left + 1:
                return pivot
            else:
                return quick_select(r + 1, right, idx - (r - left + 1))

        sz = len(nums)
        median = quick_select(0, sz - 1, sz // 2)

        larger, idx, arr = 1, 0, [median for _ in range(sz)]
        if sz % 2 == 0:
            smaller = sz - 2
        else:
            smaller = sz - 1
        for num in nums:
            if num < median:
                arr[smaller] = num
                smaller -= 2
            if num > median:
                arr[larger] = num
                larger += 2
        for i in range(sz):
            nums[i] = arr[i]


if __name__ == "__main__":
    s, nums = Solution(), [1, 4, 3, 4, 1, 2, 1, 3, 1, 3, 2, 3, 3]
    s.wiggleSort(nums)
    print(nums)
