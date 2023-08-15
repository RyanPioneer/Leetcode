"""
Source: https://rb.gy/b4lii
Date: 2023/8/15
Skill:
Ref:
Runtime: 171 ms, faster than 97.57%
Memory Usage: 27.93 MB, less than 11.95%
Time complexity:
Space complexity:
Constraints:
    Do it in-place with O(1) extra space
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverse(left, right):
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1

        k %= len(nums)
        if k == 0:
            return
        reverse(0, len(nums) - 1)
        reverse(0, k - 1)
        reverse(k, len(nums) - 1)


if __name__ == "__main__":
    s = Solution()
