"""
Source: https://rb.gy/n6kdz
Date: 2023/8/5
Skill:
Ref:
Runtime: 200 ms, faster than 52.09%
Memory Usage: 21.18 MB, less than 40.30%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def bestClosingTime(self, customers: str) -> int:
        presum, sz = [], len(customers)
        if customers[0] == "Y":
            presum.append(1)
        else:
            presum.append(0)
        for i in range(1, sz):
            if customers[i] == "Y":
                presum.append(presum[-1] + 1)
            else:
                presum.append(presum[-1])

        res, min_penalty = 0, presum[0] + (presum[-1] - presum[0])
        for i in range(1, sz):
            penalty = (i - presum[i - 1]) + (presum[-1] - presum[i - 1])
            if penalty < min_penalty:
                min_penalty = penalty
                res = i

        return res if min_penalty <= sz - presum[-1] else sz


if __name__ == "__main__":
    s = Solution()
    customers = "YYNY"
    res = s.bestClosingTime(customers)
