"""
Source: https://leetcode.com/problems/reducing-dishes/
Date: 2023/3/29
Skill:
Runtime: 41 ms, faster than 77.22%
Memory Usage: 13.8 MB, less than 77.85%
Time complexity:
Space complexity:
Constraints:
    1 <= satisfaction.length <= 500
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse=True)
        sz, presum, total, res = len(satisfaction), 0, 0, 0
        for i in range(sz):
            presum += satisfaction[i]
            total += presum
            res = max(res, total)

        return res


if __name__ == "__main__":
    s = Solution()
