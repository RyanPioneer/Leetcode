"""
Source: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
Date: 2023/2/17
Skill:
Runtime: 47 ms, faster than 93.70%
Memory Usage: 13.8 MB, less than 94.39%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        res = 0
        for operation in operations:
            if operation[1] == "+":
                res += 1
            else:
                res -= 1

        return res


if __name__ == "__main__":
    s = Solution