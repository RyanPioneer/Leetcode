"""
Source: https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/
Date: 2023/3/13
Skill:
Runtime: 944 ms, faster than 32.44%
Memory Usage: 53.2 MB, less than 72.53%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        MOD = 10 ** 9 + 7
        ranges.sort()
        group_number, left, right, sz = 1, ranges[0][0], ranges[0][1], len(ranges)
        for i in range(1, sz):
            if ranges[i][0] <= right:
                right = max(right, ranges[i][1])
            else:
                group_number += 1
                left, right = ranges[i][0], ranges[i][1]

        return 2 ** group_number % MOD


if __name__ == "__main__":
    s = Solution()
