"""
Source: https://leetcode.com/problems/number-of-great-partitions/
Date: 2023/4/23
Skill:
Ref:
Runtime: 7271 ms, faster than 6.20%
Memory Usage: 17.1 MB, less than 76.27%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length, k <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        MOD = 10 ** 9 + 7


if __name__ == "__main__":
    s = Solution()
