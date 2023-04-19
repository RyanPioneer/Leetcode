"""
Source: https://leetcode.com/problems/kth-smallest-instructions/
Date: 2023/4/18
Skill:
Ref:
Runtime: 43 ms, faster than 34.12%
Memory Usage: 13.9 MB, less than 23.53%
Time complexity:
Space complexity:
Constraints:
    destination.length == 2
    1 <= row, column <= 15
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        row, col, total, res = destination[0], destination[1], \
            destination[0] + destination[1], ""

        def comb(x, y):
            num = 1
            for i in range(x, x - y, -1):
                num *= i
            for i in range(1, y + 1):
                num //= i
            return num

        for i in range(total):
            if row == 0:
                res += "H"
            elif col == 0:
                res += "V"
            else:
                combination = comb(row + col - 1, col - 1)
                if combination >= k:
                    res += "H"
                    col -= 1
                else:
                    res += "V"
                    row -= 1
                    k -= combination

        return res


if __name__ == "__main__":
    s = Solution()
