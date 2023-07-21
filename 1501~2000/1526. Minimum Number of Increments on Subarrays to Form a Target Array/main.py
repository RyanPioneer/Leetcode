"""
Source: https://rb.gy/lal10
Date: 2023/7/18
Skill:
Ref:
Runtime: 749 ms, faster than 87.86%
Memory Usage: 28.12 MB, less than 50.87%
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
    def minNumberOperations(self, target: List[int]) -> int:
        sz, res, cur_val = len(target), 0, 0
        for i in range(sz):
            if target[i] > cur_val:
                res += target[i] - cur_val
            cur_val = target[i]

        return res


if __name__ == "__main__":
    s = Solution()
