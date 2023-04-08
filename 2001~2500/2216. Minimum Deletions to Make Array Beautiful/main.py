"""
Source: https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/
Date: 2023/4/8
Skill:
Ref:
Runtime: 1279 ms, faster than 96.48%
Memory Usage: 28.4 MB, less than 51.41%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        pos, sz, res = 0, len(nums), 0
        while pos < sz:
            next_pos = pos + 1
            while next_pos < sz and nums[pos] == nums[next_pos]:
                res += 1
                next_pos += 1
            if next_pos == sz:
                res += 1
                break
            pos = next_pos + 1

        return res


if __name__ == "__main__":
    s = Solution()
