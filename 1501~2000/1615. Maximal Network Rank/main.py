"""
Source: https://leetcode.com/problems/maximal-network-rank/
Date: 2023/8/18
Skill:
Ref:
Runtime: 312 ms, faster than 81.01%
Memory Usage: 18.06 MB, less than 72.03%
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
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        degree, edges, res = [0 for _ in range(n)], defaultdict(), 0
        for road in roads:
            degree[road[0]] += 1
            degree[road[1]] += 1
            edges[(min(road[0], road[1]), max(road[0], road[1]))] = 1

        for i in range(n - 1):
            for j in range(i + 1, n):
                if (i, j) in edges:
                    edge = 1
                else:
                    edge = 0
                res = max(res, degree[i] + degree[j] - edge)
        return res


if __name__ == "__main__":
    s = Solution()
