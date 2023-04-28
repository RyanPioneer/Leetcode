"""
Source: https://leetcode.com/problems/similar-string-groups/
Date: 2023/4/28
Skill:
Ref:
Runtime: 258 ms, faster than 80.33%
Memory Usage: 16.7 MB, less than 10.16%
Time complexity:
Space complexity:
Constraints:
    1 <= strs.length <= 300
    1 <= strs[i].length <= 300
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        father, sz, length, groups = [i for i in range(len(strs))], len(strs), len(strs[0]), set()

        def find_father(x):
            if father[x] != x:
                father[x] = father[father[x]]
            return father[x]

        def union(x, y):
            x_father, y_father = find_father(x), find_father(y)
            if x_father != y_father:
                father[max(x_father, y_father)] = min(x_father, y_father)

        def check_similar(x, y):
            time, first_idx = 0, -1
            for i in range(length):
                if x[i] != y[i]:
                    time += 1
                    if time == 1:
                        first_idx = i
                    elif time == 2:
                        if x[i] != y[first_idx] or y[i] != x[first_idx]:
                            return False
                    else:
                        return False

            return True

        for i in range(sz - 1):
            for j in range(i + 1, sz):
                if check_similar(strs[i], strs[j]):
                    union(i, j)

        for i in range(sz):
            groups.add(find_father(i))

        return len(groups)


if __name__ == "__main__":
    s = Solution()
