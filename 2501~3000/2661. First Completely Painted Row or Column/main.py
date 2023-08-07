"""
Source: https://rb.gy/cs8hk
Date: 2023/8/7
Skill:
Ref:
Runtime: 1046 ms, faster than 95.87%
Memory Usage: 53.55 MB, less than 25.08%
Time complexity:
Space complexity:
Constraints:
    1 <= m * n <= 10 ** 5
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        num2pos, m, n = defaultdict(list), len(mat), len(mat[0])
        rows, cols = [0 for _ in range(m)], [0 for _ in range(n)]
        for i in range(m):
            for j in range(n):
                num2pos[mat[i][j]] = [i, j]
        for i in range(m * n):
            [row, col] = num2pos[arr[i]]
            rows[row] += 1
            if rows[row] == n:
                return i
            cols[col] += 1
            if cols[col] == m:
                return i


if __name__ == "__main__":
    s = Solution()
