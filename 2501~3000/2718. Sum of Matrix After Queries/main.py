"""
Source: https://rb.gy/k51lb
Date: 2023/7/31
Skill:
Ref:
Runtime: 1709 ms, faster than 100.00%
Memory Usage: 39.1 MB, less than 72.54%
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
    def matrixSumQueries(self, n: int, queries: List[List[int]]) -> int:
        row, col, sz = [0 for _ in range(n)], [0 for _ in range(n)], len(queries)
        visited_row_cnt, visited_col_cnt, res = 0, 0, 0
        for i in range(sz - 1, -1, -1):
            query = queries[i]
            if query[0] == 0 and row[query[1]] == 0:
                row[query[1]] = 1
                visited_row_cnt += 1
                res += query[2] * (n - visited_col_cnt)
            if query[0] == 1 and col[query[1]] == 0:
                col[query[1]] = 1
                visited_col_cnt += 1
                res += query[2] * (n - visited_row_cnt)

        return res


if __name__ == "__main__":
    s = Solution()
