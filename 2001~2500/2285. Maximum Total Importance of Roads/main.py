"""
Source: https://leetcode.com/problems/maximum-total-importance-of-roads/description/
Date: 2023/2/11
Skill:
Runtime: 1595 ms, faster than 71.28%
Memory Usage: 39.6 MB, less than 51.1%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 5 * 10^4
    There are no duplicate roads.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        degree, res = [0 for _ in range(n)], 0
        for road in roads:
            degree[road[0]] += 1
            degree[road[1]] += 1

        degree.sort()
        for i in range(n, 0, -1):
            res += i * degree[i-1]

        return res


if __name__ == "__main__":
    s = Solution