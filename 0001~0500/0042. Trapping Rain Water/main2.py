"""
Source: https://leetcode.com/problems/trapping-rain-water/
Date: 2023/3/10
Skill: Monotonic Stack
Runtime: 129 ms, faster than 63.84%
Memory Usage: 15.8 MB, less than 95.46%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def trap(self, height: List[int]) -> int:
        stack, sz, res = [0], len(height), 0
        for i in range(1, sz):
            while stack and height[i] > height[stack[-1]]:
                pos = stack.pop()
                if stack:
                    res += (min(height[i], height[stack[-1]]) -  height[pos]) * (i - stack[-1] - 1)
            stack.append(i)

        return res


if __name__ == "__main__":
    s = Solution()
