"""
Source: https://rb.gy/gvbge
Date: 2023/7/27
Skill:
Ref:
Runtime: 384 ms, faster than 40.10%
Memory Usage: 19.46 MB, less than 28.50%
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
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        diff2profit, sz, cur_max, res = defaultdict(int), len(difficulty), 0, 0
        for i in range(sz):
            if difficulty[i] not in diff2profit:
                diff2profit[difficulty[i]] = profit[i]
            else:
                diff2profit[difficulty[i]] = max(diff2profit[difficulty[i]], profit[i])
        difficulty.sort()
        for i in range(sz):
            if diff2profit[difficulty[i]] < cur_max:
                diff2profit[difficulty[i]] = cur_max
            else:
                cur_max = diff2profit[difficulty[i]]

        for i in worker:
            pos = bisect_left(difficulty, i)
            if pos < len(difficulty) and difficulty[pos] <= i:
                res += diff2profit[difficulty[pos]]
            elif pos > 0 and difficulty[pos - 1] <= i:
                res += diff2profit[difficulty[pos - 1]]

        return res


if __name__ == "__main__":
    s = Solution()
