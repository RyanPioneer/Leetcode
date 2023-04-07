"""
Source: https://leetcode.com/problems/minimum-score-by-changing-two-elements/
Date: 2023/4/7
Skill:
Ref:
Runtime: 324 ms, faster than 97.29%
Memory Usage: 26.6 MB, less than 94.3%
Time complexity:
Space complexity:
Constraints:
    3 <= nums.length <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        nums.sort()
        return min(nums[-2] - nums[1], nums[-3] - nums[0], nums[-1] - nums[2])


if __name__ == "__main__":
    s = Solution()
