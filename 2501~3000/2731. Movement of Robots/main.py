"""
Source: https://rb.gy/96h2n
Date: 2023/7/23
Skill:
Ref:
Runtime: 507 ms, faster than 64.98%
Memory Usage: 29.44 MB, less than 23.59%
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
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        MOD, res, sz, left = 10 ** 9 + 7, 0, len(nums), 1
        for i in range(sz):
            if s[i] == "R":
                nums[i] += d
            else:
                nums[i] -= d
        nums.sort()
        for i in range(1, sz):
            res += (nums[i] - nums[i - 1]) * left * (sz - left)
            left += 1

        return res % MOD


if __name__ == "__main__":
    s = Solution()
