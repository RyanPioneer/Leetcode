"""
Source: https://rb.gy/ybm94
Date: 2023/7/18
Skill:
Ref:
Runtime: 1139 ms, faster than 78.51%
Memory Usage: 35.22 MB, less than 50.08%
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
    def maxNonDecreasingLength(self, nums1: List[int], nums2: List[int]) -> int:
        dp1, dp2, res, sz = 1, 1, 1, len(nums1)
        for i in range(1, sz):
            cur1, cur2 = 1, 1
            if nums1[i] >= nums1[i-1]:
                cur1 = max(cur1, dp1 + 1)
            if nums1[i] >= nums2[i-1]:
                cur1 = max(cur1, dp2 + 1)
            if nums2[i] >= nums1[i-1]:
                cur2 = max(cur2, dp1 + 1)
            if nums2[i] >= nums2[i-1]:
                cur2 = max(cur2, dp2 + 1)
            res = max(res, cur1, cur2)
            dp1, dp2 = cur1, cur2
        return res


if __name__ == "__main__":
    s = Solution()
