"""
Source: https://rb.gy/779b8
Date: 2023/7/17
Skill:
Ref:
Runtime: 4738 ms, faster than 30.71%
Memory Usage: 70.14 MB, less than 31.27%
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
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        visited = [1 for _ in range(n)]
        for i in range(2, math.isqrt(n)+1):
            if visited[i]:
                j = i * i
                while j < n:
                    visited[j] = 0
                    j += i
        return sum(visited) - 2


if __name__ == "__main__":
    s = Solution()
    res = s.countPrimes(10)

