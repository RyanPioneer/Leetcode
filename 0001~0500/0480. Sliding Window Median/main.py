"""
Source: https://rb.gy/bsrfu
Date: 2023/8/14
Skill:
Ref:
Runtime: 570 ms, faster than 48.08%
Memory Usage: 27.07 MB, less than 81.07%
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
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        from sortedcontainers import SortedList
        sl, sz, res = SortedList(), len(nums), []
        for i in range(k):
            sl.add(nums[i])
        if k % 2 == 1:
            res.append(sl[k // 2])
        else:
            res.append((sl[k // 2 - 1] + sl[k // 2]) / 2)
        for i in range(k, sz):
            sl.add(nums[i])
            sl.remove(nums[i - k])
            if k % 2 == 1:
                res.append(sl[k // 2])
            else:
                res.append((sl[k // 2 - 1] + sl[k // 2]) / 2)
        return res


if __name__ == "__main__":
    s = Solution()

