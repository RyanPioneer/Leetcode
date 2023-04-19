"""
Source: https://leetcode.com/problems/graph-connectivity-with-threshold/
Date: 2023/4/19
Skill:
Ref:
Runtime: 862 ms, faster than 82.35%
Memory Usage: 49.4 MB, less than 16.81%
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
    def areConnected(self, n: int, threshold: int, queries: List[List[int]]) -> List[bool]:
        father, res = [i for i in range(n + 1)], []

        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            x_father, y_father = find_father(x), find_father(y)
            if x_father != y_father:
                father[max(x_father, y_father)] = min(x_father, y_father)

        visited = [False for _ in range(threshold, n + 1)]
        for i in range(threshold + 1, n):
            if visited[i - threshold]:
                continue
            for j in range(i, n + 1, i):
                visited[j - threshold] = True
                union(i, j)

        for query in queries:
            res.append(find_father(query[0]) == find_father(query[1]))

        return res


if __name__ == "__main__":
    s = Solution()
