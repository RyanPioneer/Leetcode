"""
Source: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/
Date: 2023/2/15
Skill:
Runtime: 1208 ms, faster than 61.94%
Memory Usage: 16 MB, less than 42.61%
Time complexity:
Space complexity:
Constraints:
    1 <= banned.length <= 10^4
    1 <= banned[i], n <= 10^4
    1 <= maxSum <= 10^9
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned, res = set(banned), 0

        for i in range(1, n+1):
            if i not in banned:
                if i > maxSum:
                    break
                else:
                    maxSum -= i
                    res += 1

        return res


if __name__ == "__main__":
    s = Solution