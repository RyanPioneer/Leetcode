"""
Source: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
Date: 2023/3/24
Skill: Binary search
Runtime: 2992 ms, faster than 76.39%
Memory Usage: 28 MB, less than 94.85%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        low, high, sz = 1, 10 ** 7, len(dist)
        if hour <= sz - 1:
            return -1
        while low < high:
            mid, time = (low + high) // 2, 0
            for i in range(sz - 1):
                time += (dist[i] - 1) // mid + 1
            time += dist[sz - 1] / mid
            if time > hour:
                low = mid + 1
            else:
                high = mid

        return low


if __name__ == "__main__":
    s = Solution()
