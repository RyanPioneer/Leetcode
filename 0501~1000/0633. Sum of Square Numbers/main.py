"""
Source: https://rb.gy/ufx8f
Date: 2023/7/24
Skill:
Ref:
Runtime: 199 ms, faster than 52.89%
Memory Usage: 22.58 MB, less than 5.37%
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
    def judgeSquareSum(self, c: int) -> bool:
        upper_bound, visited = math.isqrt(c) + 1, defaultdict(int)
        for i in range(upper_bound):
            visited[i * i] = 1
            if c - i * i in visited:
                return True
        return False


if __name__ == "__main__":
    s = Solution()
