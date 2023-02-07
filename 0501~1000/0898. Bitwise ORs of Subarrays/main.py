"""
Source: https://leetcode.com/problems/bitwise-ors-of-subarrays/description/
Date: 2023/2/7
Skill:
Runtime: 801 ms, faster than 96.61%
Memory Usage: 40.3 MB, less than 67.80%
Time complexity:
Space complexity:
Constraints:
    1 <= arr.length <= 5 * 10^4
    0 <= arr[i] <= 10^9
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        res, cur = set(), set()
        for num in arr:
            cur = {num | i for i in cur} | {num}
            res |= cur

        return len(res)


if __name__ == "__main__":
    s = Solution