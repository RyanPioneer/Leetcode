"""
Source: https://rb.gy/ppiqh
Date: 2023/8/5
Skill:
Ref:
Runtime: 37 ms, faster than 92.87%
Memory Usage: 16.34 MB, less than 23.22%
Time complexity:
Space complexity:
Constraints:
    0 <= num <= 10 ** 15
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        if (num - 3) % 3 == 0:
            return [(num - 3) // 3, (num - 3) // 3 + 1, (num - 3) // 3 + 2]
        else:
            return []


if __name__ == "__main__":
    s = Solution()
