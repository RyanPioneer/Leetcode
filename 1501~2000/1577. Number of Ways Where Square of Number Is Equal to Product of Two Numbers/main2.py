"""
Source: https://rb.gy/jjq6v
Date: 2023/8/27
Skill:
Runtime: 277 ms, faster than 77.67%
Memory Usage: 16.46 MB, less than 68.93%
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
        nums1.sort()
        nums2.sort()

        def helper(arr1, arr2):
            res = 0
            for num in arr1:
                num = num ** 2
                left, right = 0, len(arr2) - 1
                while left < right:
                    if arr2[left] * arr2[right] < num:
                        left += 1
                    elif arr2[left] * arr2[right] > num:
                        right -= 1
                    elif arr2[left] == arr2[right]:
                        length = right - left + 1
                        res += length * (length - 1) // 2
                        break
                    else:
                        l, r = left, right
                        left += 1
                        right -= 1
                        while arr2[left] == arr2[left - 1]:
                            left += 1
                        while arr2[right] == arr2[right + 1]:
                            right -= 1
                        res += (left - l) * (r - right)

            return res

        return helper(nums1, nums2) + helper(nums2, nums1)


if __name__ == "__main__":
    s = Solution()
    nums1, nums2 = [4, 1, 4, 1, 12], [3, 2, 5, 4]
    res = s.numTriplets(nums2, nums1)
    print(res)
