"""
Source: https://rb.gy/0i85z
Date: 2023/8/7
Skill:
Ref:
Runtime: 132 ms, faster than 12.82%
Memory Usage: 16.25 MB, less than 82.70%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 9
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def totalNQueens(self, n: int) -> int:
        board, res = [["." for _ in range(n)] for _ in range(n)], 0

        def check_valid(x, y):
            for index in range(n):
                if index != x and board[index][y] == "Q":
                    return False
                if x - index - 1 >= 0 and y - index - 1 >= 0 and board[x - index - 1][y - index - 1] == "Q":
                    return False
                if x - index - 1 >= 0 and y + index + 1 < n and board[x - index - 1][y + index + 1] == "Q":
                    return False

            return True

        def dfs(x):
            nonlocal res
            for y in range(n):
                if check_valid(x, y):
                    board[x][y] = "Q"
                    if x == n - 1:
                        res += 1
                    else:
                        dfs(x + 1)
                    board[x][y] = "."

        dfs(0)
        return res


if __name__ == "__main__":
    s = Solution()
