"""
Source: https://leetcode.com/problems/increasing-triplet-subsequence/
Date: 2023/4/15
Skill:
Ref:
Runtime: 1164 ms, faster than 29.97%
Memory Usage: 30.1 MB, less than 74.44%
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
    def increasingTriplet(self, nums: List[int]) -> bool:
        monotonic_stack = []
        for num in nums:
            if not monotonic_stack or monotonic_stack[-1] < num:
                monotonic_stack.append(num)
            else:
                pos = bisect_left(monotonic_stack, num)
                monotonic_stack[pos] = num
            if len(monotonic_stack) == 3:
                return True

        return False


if __name__ == "__main__":
    s = Solution()
