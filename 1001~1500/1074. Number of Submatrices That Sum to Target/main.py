"""
Source: https://rb.gy/uu6g9
Date: 2023/7/24
Skill:
Ref:
Runtime: 1062 ms, faster than 17.39%
Memory Usage: 17.36 MB, less than 72.83%
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
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m, n, res = len(matrix), len(matrix[0]), 0
        for i in range(m):
            row = [0 for _ in range(n)]
            for j in range(i, m):
                for k in range(n):
                    row[k] += matrix[j][k]
                mydict, cur_sum = defaultdict(int), 0
                mydict[0] = 1  # ! Note this!!
                for k in range(n):
                    cur_sum += row[k]
                    res += mydict[cur_sum - target]
                    mydict[cur_sum] += 1

        return res


if __name__ == "__main__":
    s = Solution()
