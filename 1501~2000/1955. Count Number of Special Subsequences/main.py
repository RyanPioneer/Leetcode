"""
Source: https://rb.gy/tbrz0
Date: 2023/8/18
Skill:
Ref:
Runtime: 1547 ms, faster than 100.00%
Memory Usage: 20.25 MB, less than 64.71%
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
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        zero, one, two, mod = 0, 0, 0, 10 ** 9 + 7
        for num in nums:
            if num == 0:
                zero = (2 * zero + 1) % mod
            elif num == 1:
                one = (2 * one + zero) % mod
            else:
                two = (2 * two + one) % mod
        return two


if __name__ == "__main__":
    s = Solution()
    nums = [0, 1, 2, 0, 1, 2]
    res = s.countSpecialSubsequences(nums)
    print(res)
