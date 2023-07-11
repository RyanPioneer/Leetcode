"""
Source: https://rb.gy/7juc9
Date: 2023/7/11
Skill: Histogram
Ref:
Runtime: 1086 ms, faster than 82.86%
Memory Usage: 31 MB, less than 70%
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
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        nums.insert(0, 0)
        nums.append(0)
        stack = []
        for i in range(len(nums)):
            while stack and nums[i] < nums[stack[-1]]:
                h = nums[stack[-1]]
                stack.pop()
                area = h * (i - stack[-1] - 1)
                if area > threshold:
                    return i - stack[-1] - 1
            stack.append(i)
        return -1


if __name__ == "__main__":
    s = Solution()
