"""
Source: https://rb.gy/8gwf2
Date: 2023/7/15
Skill:
Ref:
Runtime: 2669 ms, faster than 41.45%
Memory Usage: 25.6 MB, less than 42.38%
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
    def countBlackBlocks(self, m: int, n: int, coordinates: List[List[int]]) -> List[int]:
        mydict, res = defaultdict(int), [0 for i in range(5)]
        res[0], dirs = (m-1) * (n-1), [[0, 0], [0, -1], [-1, 0], [-1, -1]]

        def check_feasible(x, y):
            return 0 <= x < m-1 and 0 <= y < n-1

        for block in coordinates:
            for dir in dirs:
                x, y = block[0] + dir[0], block[1] + dir[1]
                if check_feasible(x, y):
                    res[mydict[(x, y)]] -= 1
                    mydict[(x, y)] += 1
                    res[mydict[(x, y)]] += 1

        return res


if __name__ == "__main__":
    s = Solution()

