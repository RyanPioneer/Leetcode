"""
Source: https://leetcode.com/problems/validate-stack-sequences/
Date: 2023/4/13
Skill:
Ref:
Runtime: 73 ms, faster than 61.68%
Memory Usage: 14.1 MB, less than 34.41%
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
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack, idx, sz = [], 0, len(pushed)
        for i in range(sz):
            stack.append(pushed[i])
            while stack and idx < sz and stack[-1] == popped[idx]:
                stack.pop()
                idx += 1
        return not stack


if __name__ == "__main__":
    s = Solution()
