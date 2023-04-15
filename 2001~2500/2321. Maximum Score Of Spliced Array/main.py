"""
Source: https://leetcode.com/problems/maximum-score-of-spliced-array/
Date: 2023/4/15
Skill: Dynamic Programming
Ref:
Runtime: 1023 ms, faster than 56.12%
Memory Usage: 32.4 MB, less than 28.57%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        sz = len(nums1)
        dp1, dp2 = [nums2[i] - nums1[i] for i in range(sz)], \
            [nums1[i] - nums2[i] for i in range(sz)]
        for i in range(1, sz):
            dp1[i] = max(dp1[i], dp1[i] + dp1[i - 1])
            dp2[i] = max(dp2[i], dp2[i] + dp2[i - 1])

        return max(sum(nums1) + max(dp1), sum(nums2) + max(dp2))


if __name__ == "__main__":
    s = Solution()
    nums1, nums2 = [28, 34, 38, 14, 30, 31, 23, 7, 28, 3], [42, 35, 7, 6, 24, 30, 14, 21, 20, 34]
    res = s.maximumsSplicedArray(nums1, nums2)
    print(res)
