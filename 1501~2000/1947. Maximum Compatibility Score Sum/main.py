"""
Source: https://rb.gy/3xl5g
Date: 2023/8/6
Skill:
Ref:
Runtime: 580 ms, faster than 68.15%
Memory Usage: 16.24 MB, less than 94.81%
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
    def maxCompatibilitySum(self, students: List[List[int]], mentors: List[List[int]]) -> int:
        m, n, res = len(students), len(students[0]), 0
        nums = [[0 for _ in range(m)] for _ in range(m)]
        for i in range(m):
            for j in range(m):
                num = 0
                for k in range(n):
                    if students[i][k] == mentors[j][k]:
                        num += 1
                nums[i][j] = num

        perm = [i for i in range(m)]

        def helper(idx):
            nonlocal res
            if idx == m - 1:
                num = 0
                for i in range(m):
                    num += nums[i][perm[i]]
                res = max(res, num)
            else:
                for i in range(idx, m):
                    perm[idx], perm[i] = perm[i], perm[idx]
                    helper(idx + 1)
                    perm[idx], perm[i] = perm[i], perm[idx]

        helper(0)
        return res


if __name__ == "__main__":
    s = Solution()
