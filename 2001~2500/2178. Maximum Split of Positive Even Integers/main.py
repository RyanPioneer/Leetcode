"""
Source: https://rb.gy/zgldq
Date: 2023/8/5
Skill:
Ref:
Runtime: 345 ms, faster than 96.96%
Memory Usage: 28.87 MB, less than 92.40%
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
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        if finalSum % 2:
            return []
        res, num = [], 2
        while num * 2 < finalSum:
            res.append(num)
            finalSum -= num
            num += 2
        res.append(finalSum)
        return res


if __name__ == "__main__":
    s = Solution()
