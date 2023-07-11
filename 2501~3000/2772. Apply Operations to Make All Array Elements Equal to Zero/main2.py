"""
Source: https://rb.gy/k8zcn
Date: 2023/7/11
Skill:
Ref:
Runtime: 865 ms, faster than 58.4%
Memory Usage: 31 MB, less than 68.11%
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
    def checkArray(self, nums: List[int], k: int) -> bool:
        sz, pos, diff, base = len(nums), 0, [0 for _ in range(len(nums)+1)], 0
        while pos < sz - k + 1:
            base += diff[pos]
            if base > nums[pos]:
                return False
            dis = nums[pos] - base
            diff[pos+k] -= dis
            base += dis
            pos += 1
        while pos < sz:
            base += diff[pos]
            if nums[pos] != base:
                return False
            pos += 1
        return True


if __name__ == "__main__":
    s = Solution()
