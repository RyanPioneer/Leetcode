"""
Source: https://leetcode.com/problems/sort-an-array/
Date: 2023/3/1
Skill: Heap Sort
Ref:
Runtime: 3149 ms, faster than 13.84%
Memory Usage: 21.4 MB, less than 90.91%
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
        def maxHeapify(arr, i, n):
            max_idx = i
            if i*2+1 < n and arr[i*2+1] > arr[max_idx]:
                max_idx = i*2+1
            if i*2+2 < n and arr[i*2+2] > arr[max_idx]:
                max_idx = i*2+2

            if max_idx != i:
                arr[i], arr[max_idx] = arr[max_idx], arr[i]
                maxHeapify(arr, max_idx, n)

        def heapSort(arr):
            n = len(arr)
            for i in range(n//2-1, -1, -1):
                maxHeapify(arr, i, n)

            for i in range(n-1, 0, -1):
                arr[0], arr[i] = arr[i], arr[0]
                maxHeapify(arr, 0, i)

            return arr

        return heapSort(nums)


if __name__ == "__main__":
    s = Solution