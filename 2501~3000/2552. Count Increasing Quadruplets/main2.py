"""
Source: https://leetcode.com/problems/count-increasing-quadruplets/
Date: 2023/8/2
Skill:
Runtime: TLE
Memory Usage:
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        sz, res = len(nums), 0
        pre, post = [[0 for _ in range(sz)] for _ in range(sz + 1)], [[0 for _ in range(sz)] for _ in range(sz + 1)]
        for i in range(sz):
            pre[i + 1] = pre[i].copy()
            for j in range(sz - 1, -1, -1):
                if j > nums[i] - 1:
                    pre[i + 1][j] += 1
                else:
                    break

        for i in range(sz):
            post[sz - 1 - i] = post[sz - i].copy()
            for j in range(sz):
                if j < nums[sz - 1 - i] - 1:
                    post[sz - 1 - i][j] += 1
                else:
                    break

        for i in range(1, sz - 2):
            for j in range(i + 1, sz - 1):
                if nums[i] > nums[j]:
                    res += pre[i][nums[j] - 1] * post[j + 1][nums[i] - 1]

        return res


if __name__ == "__main__":
    s = Solution
    nums = [1,2,3,4]