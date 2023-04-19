"""
Source: https://leetcode.com/problems/find-the-most-competitive-subsequence/
Date: 2023/4/16
Skill:
Ref:
Runtime: 1259 ms, faster than 93.44%
Memory Usage: 27.2 MB, less than 45.25%
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
from bisect import bisect_left, bisect_right


class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        monotonic_stack, sz, count = [], len(nums), len(nums) - k
        for num in nums:
            while monotonic_stack and monotonic_stack[-1] > num and count:
                monotonic_stack.pop()
                count -= 1
            monotonic_stack.append(num)

        return monotonic_stack[:k]


if __name__ == "__main__":
    s = Solution()
