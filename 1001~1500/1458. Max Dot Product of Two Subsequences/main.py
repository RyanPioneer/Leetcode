"""
Source: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
Date: 2023/4/21
Skill:
Ref:
Runtime: 512 ms, faster than 48.31%
Memory Usage: 21.4 MB, less than 33.71%
Time complexity:
Space complexity:
Constraints:
    1 <= nums1.length, nums2.length <= 500
    -1000 <= nums1[i], nums2[i] <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        sz1, sz2 = len(nums1), len(nums2)
        nums1.insert(0, 0)
        nums2.insert(0, 0)
        dp = [[-math.inf for _ in range(sz2 + 1)] for _ in range(sz1 + 1)]
        for i in range(1, sz1 + 1):
            for j in range(1, sz2 + 1):
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                dp[i][j] = max(max(dp[i - 1][j - 1], 0) + nums1[i] * nums2[j], dp[i][j])

        return dp[sz1][sz2]


if __name__ == "__main__":
    s = Solution()
