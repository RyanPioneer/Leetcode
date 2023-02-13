"""
Source: https://leetcode.com/problems/maximum-product-of-three-numbers/description/
Date: 2023/2/13
Skill:
Runtime: 750 ms, faster than 79.11%
Memory Usage: 31.2 MB, less than 53.24%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if k == 0:
            return 0 if nums1 == nums2 else -1
        dec, inc, sz = 0, 0, len(nums1)
        for i in range(sz):
            if nums1[i] > nums2[i]:
                if (nums1[i] - nums2[i]) % k != 0:
                    return -1
                dec += (nums1[i] - nums2[i]) // k
            elif nums1[i] < nums2[i]:
                if (nums2[i] - nums1[i]) % k != 0:
                    return -1
                inc += (nums2[i] - nums1[i]) // k

        return inc if inc == dec else -1


if __name__ == "__main__":
    s = Solution