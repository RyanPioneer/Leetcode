"""
Source: https://rb.gy/93l2b
Date: 2023/7/26
Skill:
Ref:
Runtime: 917 ms, faster than 36.02%
Memory Usage: 33.14 MB, less than 25.39%
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
    def minIncrementForUnique(self, nums: List[int]) -> int:
        sz, visited, res = len(nums), set(), 0
        nums.sort()
        visited.add(nums[-1])
        stack = [[nums[-1], -1]]
        for i in range(sz - 2, -1, -1):
            if nums[i] in visited:
                res += (stack[-1][0] + 1 - nums[i])
                stack[-1][0] += 1
                if stack[-1][1] != -1:
                    if stack[-1][1] == 1:
                        stack.pop()
                    else:
                        stack[-1][1] -= 1
            else:
                visited.add(nums[i])
                if nums[i+1] - nums[i] > 1:
                    stack.append([nums[i], nums[i+1] - nums[i] - 1])

        return res


if __name__ == "__main__":
    s = Solution()
