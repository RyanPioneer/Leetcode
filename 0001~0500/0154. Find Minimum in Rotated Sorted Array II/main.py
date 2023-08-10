"""
Source: https://rb.gy/7oabr
Date: 2023/8/10
Skill:
Ref:
Runtime: 52 ms, faster than 94.55%
Memory Usage: 17.00 MB, less than 28.61%
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
    def findMin(self, nums: List[int]) -> int:
        left, right, res = 0, len(nums) - 1, sys.maxsize
        while left < right:
            mid = (left + right) // 2
            if nums[right] < nums[mid]:
                left = mid + 1
            elif nums[right] > nums[mid]:
                right = mid
            else:
                right -= 1
        return nums[left]


if __name__ == "__main__":
    s = Solution()
