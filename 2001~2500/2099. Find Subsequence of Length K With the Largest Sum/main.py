"""
Source: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
Date: 2023/2/10
Skill:
Runtime: 59 ms, faster than 70.57%
Memory Usage: 14.1 MB, less than 94.69%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        heap, res = [], []
        for idx, num in enumerate(nums):
            if len(heap) == k:
                heappushpop(heap, (num, idx))
            else:
                heappush(heap, (num, idx))

        heap.sort(key=lambda x: x[1])
        for i in heap:
            res.append(i[0])

        return res


if __name__ == "__main__":
    s = Solution