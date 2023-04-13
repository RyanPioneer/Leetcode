"""
Source: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
Date: 2023/4/13
Skill:
Ref:
Runtime: 1230 ms, faster than 72.50%
Memory Usage: 18.1 MB, less than 95%
Time complexity:
Space complexity:
Constraints:
    1 <= nums1.length, nums2.length <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        if sum(nums1) < sum(nums2):
            nums1, nums2 = nums2, nums1
        sum1, sum2, sz1, sz2 = sum(nums1), sum(nums2), len(nums1), len(nums2)
        if 6 * sz2 < sz1:
            return -1
        nums1.sort()
        nums2.sort()
        lower_bound, upper_bound = 1, 6
        left1, right1, left2, right2, diff, res = 0, sz1 - 1, 0, sz2 - 1, sum1 - sum2, 0
        while diff > 0 and (right1 >= 0 or left2 < sz2):
            if right1 >= 0 and (left2 == sz2 or nums1[right1] - 1 > 6 - nums2[left2]):
                diff -= nums1[right1] - 1
                right1 -= 1
            else:
                diff -= 6 - nums2[left2]
                left2 += 1
            res += 1

        return res if diff <= 0 else -1


if __name__ == "__main__":
    s = Solution()
