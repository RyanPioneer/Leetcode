"""
Source: https://rb.gy/9u347
Date: 2023/8/16
Skill:
Ref:
Runtime: 62 ms, faster than 43.41%
Memory Usage: 16.49 MB, less than 80.24%
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
    def equationsPossible(self, equations: List[str]) -> bool:
        father = [i for i in range(26)]

        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            x_father, y_father = find_father(x), find_father(y)
            if x_father != y_father:
                father[x_father] = y_father

        for equation in equations:
            x, y = equation[0], equation[3]
            if x != y and equation[1] == "=":
                union(ord(x) - ord("a"), ord(y) - ord("a"))
            elif x == y and equation[1] == "!":
                return False

        for equation in equations:
            x, y = equation[0], equation[3]
            if equation[1] == "!" and find_father(ord(x) - ord("a")) == find_father(ord(y) - ord("a")):
                return False
        return True


if __name__ == "__main__":
    s = Solution()
