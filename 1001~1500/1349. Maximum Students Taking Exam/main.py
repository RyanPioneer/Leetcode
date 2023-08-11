"""
Source: https://rb.gy/ddrcw
Date: 2023/8/11
Skill:
Ref:
Runtime: 566 ms, faster than 6.95%
Memory Usage: 16.26 MB, less than 96.52%
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
    def maxStudents(self, seats: List[List[str]]) -> int:
        m, n = len(seats), len(seats[0])
        dp, sz = [0 for _ in range(1 << n)], 1 << n

        def check_row_ok(num, idx):
            row = []
            for i in range(n):
                if seats[idx][i] == "#" and num % 2 == 1:
                    return False
                row.append(num % 2)
                num //= 2
            for i in range(n - 1):
                if row[i] == 1 and row[i + 1] == 1:
                    return False
            return True

        def check_col_ok(prev_row, cur_row):
            row1, row2 = [], []
            for _ in range(n):
                row1.append(prev_row % 2)
                prev_row //= 2
                row2.append(cur_row % 2)
                cur_row //= 2
            for i in range(n):
                if row2[i] == 1:
                    if i > 0 and row1[i - 1] == 1:
                        return False
                    if i < n - 1 and row1[i + 1] == 1:
                        return False
            return True

        def count_seat(num):
            cnt = 0
            for _ in range(n):
                if num % 2 == 1:
                    cnt += 1
                num //= 2
            return cnt

        for i in range(m):
            dp2 = [0 for _ in range(sz)]
            for j in range(sz):
                if not check_row_ok(j, i):
                    continue
                if i == 0:
                    dp2[j] = count_seat(j)
                else:
                    for k in range(sz):
                        if not check_row_ok(k, i - 1):
                            continue
                        if check_col_ok(k, j):
                            dp2[j] = max(dp2[j], dp[k] + count_seat(j))
            dp = dp2

        return max(dp)


if __name__ == "__main__":
    s = Solution()
