"""
Source: https://rb.gy/d46id
Date: 2023/7/18
Skill:
Ref:
Runtime: 1432 ms, faster than 72.23%
Memory Usage: 29.7 MB, less than 19.71%
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
    def reversePairs(self, nums: List[int]) -> int:
        res = 0

        def divide_and_conquer(left, right):
            nonlocal res
            if left >= right:
                return
            mid = (left + right) // 2
            divide_and_conquer(left, mid)
            divide_and_conquer(mid+1, right)
            r = mid
            for i in range(left, mid+1):
                while r < right and nums[i] > nums[r+1] * 2:
                    r += 1
                res += r - mid
            nums[left: right+1] = sorted(nums[left: right+1])

        divide_and_conquer(0, len(nums)-1)
        return res


if __name__ == "__main__":
    s = Solution()
