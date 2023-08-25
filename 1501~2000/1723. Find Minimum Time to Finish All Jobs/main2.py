"""
Source: https://rb.gy/t0jjq
Date: 2023/8/25
Skill:
Runtime: 7913 ms, faster than 6.98%
Memory Usage: 126.37 MB, less than 6.98%
Time complexity:
Space complexity:
Constraints:
    1 <= k <= jobs.length <= 12
    1 <= jobs[i] <= 10 ** 7
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:



if __name__ == "__main__":
    s = Solution()
    jobs, k = [1, 2, 4, 7, 8], 2
    res = s.minimumTimeRequired(jobs, k)
    print(res)
