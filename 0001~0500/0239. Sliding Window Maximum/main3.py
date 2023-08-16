"""
Source: https://rb.gy/f1aau
Date: 2023/8/16
Skill:
Ref:
Runtime: 1266 ms, faster than 98.89%
Memory Usage: 33.17 MB, less than 64.19%
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
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res, sz, q = [], len(nums), deque()
        for i in range(k):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
        res.append(nums[q[0]])
        for i in range(k, sz):
            if q and q[0] == i - k:
                q.popleft()
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            res.append(nums[q[0]])
        return res


if __name__ == "__main__":
    s = Solution()

