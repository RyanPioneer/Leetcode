"""
Source: https://rb.gy/n8pl3
Date: 2023/8/25
Skill:
Runtime: 1863 ms, faster than 77.62%
Memory Usage: 53.11 MB, less than 98.60%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 10 ** 5
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        meetings.sort(key=lambda x: x[2])
        father, res, sz, idx, res = [i for i in range(n)], [], len(meetings), 0, []

        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            x_father, y_father = find_father(x), find_father(y)
            if x_father != y_father:
                father[max(x_father, y_father)] = min(x_father, y_father)

        union(0, firstPerson)
        while idx < sz:
            cur_time, pos = meetings[idx][2], idx
            union(meetings[idx][0], meetings[idx][1])
            idx += 1
            while idx < sz and meetings[idx][2] == cur_time:
                union(meetings[idx][0], meetings[idx][1])
                idx += 1
            for i in range(pos, idx):
                if find_father(meetings[i][0]) != 0:
                    father[meetings[i][0]] = meetings[i][0]
                    father[meetings[i][1]] = meetings[i][1]

        for i in range(n):
            if find_father(i) == 0:
                res.append(i)
        return res


if __name__ == "__main__":
    s = Solution()
