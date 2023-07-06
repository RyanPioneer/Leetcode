"""
Source: https://rb.gy/1mfom
Date: 2023/7/6
Skill:
Ref:
Runtime: 92 ms, faster than 93.13%
Memory Usage: 16.7 MB, less than 64.50%
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
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        def findSmallerOrEqual(num):
            cnt, j = 0, len(arr) - 1
            for i in range(len(arr) - 1, -1, -1):
                while j >= 0 and arr[j] / arr[i] > num:
                    j -= 1
                cnt += j + 1
            return cnt

        lower_bound, upper_bound, mid = 0, 1, 0
        while lower_bound < upper_bound:
            mid = (lower_bound + upper_bound) / 2
            cnt = findSmallerOrEqual(mid)
            if cnt > k:
                upper_bound = mid
            elif cnt < k:
                lower_bound = mid
            else:
                break
        ans, res, j = 0, [], len(arr) - 1
        for i in range(len(arr) - 1, -1, -1):
            while j >= 0 and arr[j] / arr[i] > mid:
                j -= 1
            if j < 0:
                break
            if arr[j] / arr[i] > ans:
                ans = arr[j] / arr[i]
                res = [arr[j], arr[i]]
        return res


if __name__ == "__main__":
    s = Solution()
    arr, k = [1, 2, 3, 5], 3
    res = s.kthSmallestPrimeFraction(arr, k)
    print(res)
