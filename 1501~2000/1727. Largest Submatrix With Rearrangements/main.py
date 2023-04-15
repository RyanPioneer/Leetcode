"""
Source: https://leetcode.com/problems/largest-submatrix-with-rearrangements/
Date: 2023/4/15
Skill:
Ref:
Runtime: 1284 ms, faster than 88.24%
Memory Usage: 37.5 MB, less than 88.24%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        hist, res = [0 for _ in range(n)], 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1:
                    hist[j] += 1
                else:
                    hist[j] = 0
            cur_row = hist.copy()
            cur_row.sort(reverse=True)
            for k in range(n):
                res = max(res, cur_row[k] * (k + 1))

        return res


if __name__ == "__main__":
    s = Solution()
