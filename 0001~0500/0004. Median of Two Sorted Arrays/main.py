"""
Source: https://leetcode.com/problems/median-of-two-sorted-arrays/
Date: 2022/2/18
Constraints: 
    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -10^6 <= nums1[i], nums2[i] <= 10^6
    !The overall run time complexity should be O(log (m+n)).
"""

from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        