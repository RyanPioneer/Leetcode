"""
Source: https://rb.gy/psc1r
Date: 2023/8/6
Skill:
Ref:
Runtime: 3246 ms, faster than 100.00%
Memory Usage: 50.77 MB, less than 100.00%
Time complexity:
Space complexity:
Constraints:
    1 <= nums1.length <= 10 ** 3
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
        arr, sz = [], len(nums1)
        for i in range(sz):
            arr.append([nums1[i], nums2[i]])
        arr.sort(key=lambda y: y[1])
        arr.insert(0, [0, 0])
        dp, presum = [[0 for _ in range(sz + 1)] for _ in range(sz + 1)], [arr[i][1] for i in range(sz + 1)]
        for i in range(sz):
            presum[i + 1] += presum[i]
            dp[i + 1][0] = dp[i][0] + arr[i + 1][0]
        if dp[-1][0] <= x:
            return 0
        for i in range(1, sz + 1):
            for j in range(1, sz + 1):
                dp[i][j] = min(dp[i - 1][j] + arr[i][0] + arr[i][1] * j, dp[i - 1][j - 1] + presum[i - 1])
                if i == sz and dp[i][j] <= x:
                    return j

        return -1


if __name__ == "__main__":
    s = Solution()
