"""
Source: https://rb.gy/ap2re
Date: 2023/8/20
Skill:
Runtime: 53 ms, faster than 100.00%
Memory Usage: 16.4 MB, less than 100.00%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        res, dict, num = 0, defaultdict(int), 1
        for _ in range(n):
            while k - num in dict:
                num += 1
            res += num
            dict[num] = 1
            num += 1
        return res


if __name__ == "__main__":
    s = Solution()
