"""
Source: https://leetcode.com/problems/wiggle-subsequence/
Date: 2023/4/21
Skill:
Ref:
Runtime: 31 ms, faster than 89.23%
Memory Usage: 13.9 MB, less than 65.32%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        sz, p, q = len(nums), 1, 1
        for i in range(1, sz):
            if nums[i] > nums[i - 1]:
                p = q + 1
            elif nums[i] < nums[i - 1]:
                q = p + 1

        return max(p, q)


if __name__ == "__main__":
    s = Solution()
