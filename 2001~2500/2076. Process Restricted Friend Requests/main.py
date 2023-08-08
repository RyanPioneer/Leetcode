"""
Source: https://rb.gy/6iwd5
Date: 2023/8/8
Skill:
Ref:
Runtime: 2707 ms, faster than 67.48%
Memory Usage: 17.16 MB, less than 57.72%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 1000
    0 <= restrictions.length <= 1000
    1 <= requests.length <= 1000
"""


import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def friendRequests(self, n: int, restrictions: List[List[int]], requests: List[List[int]]) -> List[bool]:
        father, res = [i for i in range(n)], []
        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            x_father, y_father = find_father(x), find_father(y)
            if x_father != y_father:
                father[x_father] = y_father

        for request in requests:
            group1, group2, flag = find_father(request[0]), find_father(request[1]), True
            for restrict in restrictions:
                r1, r2 = find_father(restrict[0]), find_father(restrict[1])
                if (r1 == group1 and r2 == group2) or (r1 == group2 and r2 == group1):
                    flag = False
                    break
            res.append(flag)
            if flag:
                union(group1, group2)

        return res


if __name__ == "__main__":
    s = Solution()
