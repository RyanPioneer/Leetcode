"""
Source: https://rb.gy/ea0fm
Date: 2023/7/31
Skill:
Ref:
Runtime: 76 ms, faster than 96.35%
Memory Usage: 16.62 MB, less than 51.19%
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
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        presum, suffsum, sz, res = [0 for _ in range(len(nums))], [0 for _ in range(len(nums))], len(nums), []
        for i in range(sz - 1):
            presum[i + 1] = nums[i] + presum[i]
            suffsum[sz - 2 - i] = nums[sz - 1 - i] + suffsum[sz - 1 - i]
        for i in range(sz):
            res.append(abs(presum[i] - suffsum[i]))
        return res


if __name__ == "__main__":
    s = Solution()
