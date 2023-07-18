"""
Source: https://rb.gy/86zri
Date: 2023/7/17
Skill:
Ref:
Runtime: TLE
Memory Usage:
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
            for i in range(left, mid+1):
                pos1 = bisect_left(presum[mid+1: right+1], presum[i] + lower)
                pos2 = bisect_right(presum[mid+1: right+1], presum[i] + upper)
                res += pos2 - pos1

            tmp, l, r = [], left, mid+1
            while l <= mid and r <= right:
                if presum[l] < presum[r]:
                    tmp.append(presum[l])
                    l += 1
                else:
                    tmp.append(presum[r])
                    r += 1
            while l <= mid:
                tmp.append(presum[l])
                l += 1
            while r <= right:
                tmp.append(presum[r])
                r += 1
            presum[left: right+1] = tmp

        divide_and_conquer(0, sz)
        return res


if __name__ == "__main__":
    s = Solution()
