"""
Source: https://leetcode.com/problems/median-of-two-sorted-arrays/
Date: 2023/3/4
Skill:
Runtime: 100 ms, faster than 47.47%
Memory Usage: 14.2 MB, less than 16.78%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        length1, length2 = len(nums1), len(nums2)

        def FindKthSmallest(arr1, start1, len1, arr2, start2, len2, k):
            if len1 - start1 > len2 - start2:
                return FindKthSmallest(arr2, start2, len2, arr1, start1, len1, k)
            if start1 == len1:
                return arr2[start2 + k - 1]
            if k == 1:
                return min(arr1[start1], arr2[start2])
            k1 = min(k // 2, len1 - start1)
            k2 = k - k1
            if arr1[start1 + k1 - 1] > arr2[start2 + k2 - 1]:
                return FindKthSmallest(arr1, start1, len1, arr2, start2 + k2, len2, k - k2)
            else:
                return FindKthSmallest(arr1, start1 + k1, len1, arr2, start2, len2, k - k1)

        if (length1 + length2) % 2 == 1:
            return FindKthSmallest(nums1, 0, length1, nums2, 0, length2, (length1 + length2 + 1) // 2)
        else:
            return (FindKthSmallest(nums1, 0, length1, nums2, 0, length2, (length1 + length2) // 2)
                    + FindKthSmallest(nums1, 0, length1, nums2, 0, length2, (length1 + length2) // 2 + 1)) / 2
