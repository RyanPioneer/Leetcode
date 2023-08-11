"""
Source: https://rb.gy/7c399
Date: 2023/8/11
Skill:
Ref:
Runtime: 77 ms, faster than 60.28%
Memory Usage: 16.46 MB, less than 43.97%
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
    def numOfWays(self, n: int) -> int:
        mod, aba, abc = 10 ** 9 + 7, 6, 6
        for _ in range(n - 1):
            prev_aba, prev_abc = aba, abc
            aba = 3 * prev_aba + 2 * prev_abc
            abc = 2 * prev_aba + 2 * prev_abc
        return (aba + abc) % mod


if __name__ == "__main__":
    s = Solution()
