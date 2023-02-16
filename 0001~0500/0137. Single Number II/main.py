"""
Source: https://leetcode.com/problems/single-number-ii/
Date: 2023/2/16
Skill:
Runtime: 150 ms, faster than 26.80%
Memory Usage: 15.7 MB, less than 86.51%
Time complexity:
Space complexity:
Constraints:
    -2^31 <= nums[i] <= 2^31 - 1
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        bits, res = [0 for _ in range(32)], 0
        for num in nums:
            for i in range(32):
                bits[i] += (num >> i) & 1

        for i in range(31):
            if bits[i] % 3 != 0:
                res += 1 << i

        return res if bits[31] % 3 == 0 else res - (1 << 31)


if __name__ == "__main__":
    s = Solution
    nums = [2,2,-3,2]
    res = s.singleNumber(s, nums)
    print(res)