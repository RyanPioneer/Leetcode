"""
Source: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
Date: 2023/4/12
Skill:
Ref:
Runtime: 505 ms, faster than 71.17%
Memory Usage: 24 MB, less than 67.48%
Time complexity:
Space complexity:
Constraints:
    1 <= arr[i] <= 10^9
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        arr[0], sz = 1, len(arr)
        for i in range(1, sz):
            if arr[i] > arr[i - 1] + 1:
                arr[i] = arr[i - 1] + 1
        return arr[sz - 1]


if __name__ == "__main__":
    s = Solution()
