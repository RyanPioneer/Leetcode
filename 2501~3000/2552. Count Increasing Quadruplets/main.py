"""
Source: https://leetcode.com/problems/count-increasing-quadruplets/
Date: 2023/2/17
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
        pre, post, sz, res = [[0 for _ in range(len(nums))] for _ in range(len(nums))]\
            , [[0 for _ in range(len(nums))] for _ in range(len(nums))], len(nums), 0
        for i in range(sz):
            if nums[0]-1 < i:
                pre[0][i] = 1
            if nums[sz-1]-1 > i:
                post[sz-1][i] = 1

        for i in range(1, sz):
            for j in range(sz):
                if nums[i]-1 < j:
                    pre[i][j] = pre[i-1][j] + 1
                else:
                    pre[i][j] = pre[i - 1][j]
                if nums[sz-1-i]-1 > j:
                    post[sz-1-i][j] = post[sz-i][j] + 1
                else:
                    post[sz-1-i][j] = post[sz-i][j]


        for j in range(1, sz-2):
            for k in range(j+1, sz-1):
                if nums[k] < nums[j]:
                    res += pre[j-1][nums[k]-1] * post[k+1][nums[j]-1]

        return res


if __name__ == "__main__":
    s = Solution
    nums = [1,2,3,4]