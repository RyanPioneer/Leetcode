"""
Source: https://leetcode.com/problems/get-the-maximum-score/
Date: 2023/4/18
Skill:
Ref:
Runtime: 589 ms, faster than 80.14%
Memory Usage: 25.8 MB, less than 75.18%
Time complexity:
Space complexity:
Constraints:
    nums1 and nums2 are strictly increasing.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        pointer1, pointer2, res = len(nums1) - 1, len(nums2) - 1, 0
        sum1, sum2, MOD = 0, 0, 10 ** 9 + 7
        while pointer1 >= 0 and pointer2 >= 0:
            if nums1[pointer1] == nums2[pointer2]:
                res += max(sum1, sum2) + nums1[pointer1]
                sum1, sum2 = 0, 0
                pointer1 -= 1
                pointer2 -= 1
            elif nums1[pointer1] > nums2[pointer2]:
                sum1 += nums1[pointer1]
                pointer1 -= 1
            else:
                sum2 += nums2[pointer2]
                pointer2 -= 1

        while pointer1 >= 0:
            sum1 += nums1[pointer1]
            pointer1 -= 1

        while pointer2 >= 0:
            sum2 += nums2[pointer2]
            pointer2 -= 1

        res += max(sum1, sum2)
        return res % MOD


if __name__ == "__main__":
    s = Solution()
