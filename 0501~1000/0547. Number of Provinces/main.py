"""
Source: https://leetcode.com/problems/number-of-provinces/
Date: 2023/4/11
Skill: Union_Find
Ref:
Runtime: 190 ms, faster than 61.43%
Memory Usage: 14.1 MB, less than 99.77%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 200
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        father, sz, res = [i for i in range(len(isConnected))], len(isConnected), set()

        def find_father(i):
            if father[i] != i:
                father[i] = find_father(father[i])
            return father[i]

        def union(x, y):
            x_father, y_father = find_father(x), find_father(y)
            if x_father != y_father:
                father[max(x_father, y_father)] = min(x_father, y_father)

        for i in range(sz):
            for j in range(sz):
                if isConnected[i][j] == 1 and i != j:
                    union(i, j)

        for i in range(sz):
            res.add(find_father(i))

        return len(res)


if __name__ == "__main__":
    s = Solution()
