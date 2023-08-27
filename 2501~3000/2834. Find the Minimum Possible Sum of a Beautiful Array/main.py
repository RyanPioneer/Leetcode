"""
Source: https://rb.gy/741uh
Date: 2023/8/27
Skill:
Runtime: 98 ms, faster than 66.67%
Memory Usage: 29.7 MB, less than 33.33%
Time complexity:
Space complexity:
Constraints:

"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def minimumPossibleSum(self, n: int, target: int) -> int:
        res, dict, num = [], defaultdict(int), 1
        for _ in range(n):
            while target - num in dict:
                num += 1
            res.append(num)
            dict[num] = 1
            num += 1
        return sum(res)


if __name__ == "__main__":
    s = Solution()
