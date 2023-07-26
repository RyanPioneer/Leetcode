"""
Source: https://rb.gy/9d4bs
Date: 2023/7/26
Skill:
Ref:
Runtime: 1428 ms, faster than 85.38%
Memory Usage: 26.64 MB, less than 99.53%
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
    def maximumProduct(self, nums: List[int], k: int) -> int:
        MOD, res = 10 ** 9 + 7, 1
        heapify(nums)
        for _ in range(k):
            heappush(nums, heappop(nums) + 1)

        for num in nums:
            res *= num
            res %= MOD  # * Note!
        return res % MOD


if __name__ == "__main__":
    s = Solution()
    nums, k = [9, 7, 8], 9
    res = s.maximumProduct(nums, k)
