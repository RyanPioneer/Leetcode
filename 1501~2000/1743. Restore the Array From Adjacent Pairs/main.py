"""
Source: https://rb.gy/nmjm6
Date: 2023/8/21
Skill:
Ref:
Runtime: 1055 ms, faster than 62.93%
Memory Usage: 66.47 MB, less than 67.96%
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
from functools import cache


class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        adj_list, degree, n = defaultdict(list), defaultdict(int), len(adjacentPairs) + 1
        for a, b in adjacentPairs:
            adj_list[a].append(b)
            adj_list[b].append(a)
            degree[a] += 1
            degree[b] += 1

        q, left, right, is_left, res = deque(), 0, n - 1, True, [0 for _ in range(n)]
        for key, val in degree.items():
            if val == 1:
                q.append([key, is_left])
                is_left = not is_left
                degree[key] = 0

        while q:
            num, is_left = q.popleft()
            if is_left:
                res[left] = num
                left += 1
            else:
                res[right] = num
                right -= 1
            for adj in adj_list[num]:
                degree[adj] -= 1
                if degree[adj] == 1:
                    q.append([adj, is_left])
                    degree[adj] = 0

        return res


if __name__ == "__main__":
    s = Solution()
