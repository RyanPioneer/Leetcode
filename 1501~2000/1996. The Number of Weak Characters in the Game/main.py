"""
Source: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
Date: 2023/4/12
Skill:
Ref:
Runtime: 2189 ms, faster than 71.27%
Memory Usage: 67.1 MB, less than 66.1%
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
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda x: (x[0], -x[1]))
        stack, sz = [], len(properties)
        for i in range(sz):
            while stack and stack[-1] < properties[i][1]:
                stack.pop()
            stack.append(properties[i][1])

        return sz - len(stack)


if __name__ == "__main__":
    s = Solution()
