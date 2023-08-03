"""
Source: https://rb.gy/q49pv
Date: 2023/8/3
Skill:
Ref:
Runtime: 296 ms, faster than 98.32%
Memory Usage: 31.09 MB, less than 61.34%
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
    def xorBeauty(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            res ^= num
        return res


if __name__ == "__main__":
    s = Solution()
