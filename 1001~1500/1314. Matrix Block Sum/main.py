"""
Source: https://rb.gy/bbzh9
Date: 2023/8/14
Skill:
Ref:
Runtime: 152 ms, faster than 38.49%
Memory Usage: 17.25 MB, less than 99.31%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n, k <= 100
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        res, num = [[0 for _ in range(n)] for _ in range(m)], 0
        for i in range(min(k + 1, m)):
            for j in range(min(k + 1, n)):
                num += mat[i][j]
        res[0][0] = num
        for i in range(1, m):
            if i - k - 1 >= 0:
                for j in range(min(k + 1, n)):
                    num -= mat[i - k - 1][j]
            if i + k < m:
                for j in range(min(k + 1, n)):
                    num += mat[i + k][j]
            res[i][0] = num
        for i in range(1, n):
            num = res[0][i - 1]
            if i - k - 1 >= 0:
                for j in range(min(k + 1, m)):
                    num -= mat[j][i - k - 1]
            if i + k < n:
                for j in range(min(k + 1, m)):
                    num += mat[j][i + k]
            res[0][i] = num
            for j in range(1, m):
                if j - k - 1 >= 0:
                    for l in range(max(0, i - k), min(n, i + k + 1)):
                        num -= mat[j - k - 1][l]
                if j + k < m:
                    for l in range(max(0, i - k), min(n, i + k + 1)):
                        num += mat[j + k][l]
                res[j][i] = num

        return res


if __name__ == "__main__":
    s = Solution()
    mat, k = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], 1
    res = s.matrixBlockSum(mat, k)
    print(res)
