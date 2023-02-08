"""
Source: https://leetcode.com/problems/maximum-subsequence-score/
Date: 2023/2/8
Skill:
Runtime: 1037 ms, faster than 95.86%
Memory Usage: 34.6 MB, less than 89.5%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        cur_min, cur_sum, res = math.inf, 0, 0
        heap: List = []
        for num2, num1 in sorted(zip(nums2, nums1), reverse=True):
            cur_min = num2
            cur_sum += num1
            heappush(heap, num1)
            if len(heap) == k:
                res = max(res, cur_sum * cur_min)
                val = heappop(heap)
                cur_sum -= val

        return res



if __name__ == "__main__":
    s = Solution
    nums1, nums2, k = [1,3,3,2], [2,1,3,4], 3
    s.maxScore(s, nums1, nums2, k)