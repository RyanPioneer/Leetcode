"""
Source: https://rb.gy/318du
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
    def countSmaller(self, nums: List[int]) -> List[int]:
        sorted_nums, sz, cnt = nums.copy(), len(nums), [0 for _ in range(len(nums))]

        def divideAndConquer(left, right):
            if left >= right:
                return
            mid = (left + right) // 2
            divideAndConquer(left, mid)
            divideAndConquer(mid+1, right)
            for i in range(left, mid+1):
                pos = bisect_left(sorted_nums[mid+1: right+1], nums[i])
                cnt[i] += pos
            l, r, tmp = left, mid+1, []
            while l <= mid and r <= right:
                if sorted_nums[l] <= sorted_nums[r]:
                    tmp.append(sorted_nums[l])
                    l += 1
                else:
                    tmp.append(sorted_nums[r])
                    r += 1
            while l <= mid:
                tmp.append(sorted_nums[l])
                l += 1
            while r <= right:
                tmp.append(sorted_nums[r])
                r += 1
            sorted_nums[left:right+1] = tmp.copy()

        divideAndConquer(0, sz-1)
        return cnt


if __name__ == "__main__":
    s = Solution()

