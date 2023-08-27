"""
Source: https://rb.gy/jjq6v
Date: 2023/8/27
Skill:
Runtime: 693 ms, faster than 22.33%
Memory Usage: 16.4 MB, less than 91.26%
Time complexity:
Space complexity:
Constraints:
    1 <= nums1.length, nums2.length <= 1000
    1 <= nums1[i], nums2[i] <= 10 ** 5
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        def helper(arr1, arr2):
            res = 0
            for num in arr1:
                num = num ** 2
                dict = defaultdict(int)
                for num2 in arr2:
                    if num % num2 == 0:
                        res += dict[num // num2]
                    dict[num2] += 1
            return res

        return helper(nums1, nums2) + helper(nums2, nums1)


if __name__ == "__main__":
    s = Solution()
