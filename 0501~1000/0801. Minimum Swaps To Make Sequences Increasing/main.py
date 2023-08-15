"""
Source: https://rb.gy/mk9hr
Date: 2023/8/15
Skill:
Ref:
Runtime: 1008 ms, faster than 75.31%
Memory Usage: 40.27 MB, less than 34.16%
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
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        sz = len(nums1)
        dp = [[sys.maxsize for _ in range(2)] for _ in range(sz)]
        dp[0][0], dp[0][1] = 0, 1
        for i in range(1, sz):
            if nums1[i] <= nums1[i - 1] or nums2[i] <= nums2[i - 1]:
                dp[i][1], dp[i][0] = dp[i - 1][0] + 1, dp[i - 1][1]
            elif nums1[i] <= nums2[i - 1] or nums2[i] <= nums1[i - 1]:
                dp[i][1], dp[i][0] = dp[i - 1][1] + 1, dp[i - 1][0]
            else:
                dp[i][1], dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1, min(dp[i - 1][0], dp[i - 1][1])

        return min(dp[-1])


if __name__ == "__main__":
    s = Solution()
