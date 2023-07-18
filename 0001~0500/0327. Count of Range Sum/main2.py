"""
Source: https://rb.gy/86zri
Date: 2023/7/18
Skill:
Ref:
Runtime: 2442 ms, faster than 65.16%
Memory Usage: 50.97 MB, less than 11.50%
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
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        presum, sz, res = [0 for _ in range(len(nums)+1)], len(nums), 0
        for i in range(sz):
            presum[i+1] = presum[i] + nums[i]

        def divide_and_conquer(left, right):
            nonlocal res
            if left >= right:
                return
            mid = (left + right) // 2
            divide_and_conquer(left, mid)
            divide_and_conquer(mid+1, right)

            l, r = mid+1, mid+1
            for i in range(left, mid+1):
                while l <= right and presum[l] < presum[i] + lower:
                    l += 1
                while r <= right and presum[r] <= presum[i] + upper:
                    r += 1
                res += r - l
            presum[left: right+1] = sorted(presum[left: right+1])

        divide_and_conquer(0, sz)
        return res


if __name__ == "__main__":
    s = Solution()
