"""
Source: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
Date: 2023/4/14
Skill:
Ref:
Runtime: 1432 ms, faster than 68.75%
Memory Usage: 60.4 MB, less than 70%
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
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        father, sz = [i for i in range(len(source))], len(source)

        def find_father(i):
            if father[i] != i:
                father[i] = find_father(father[i])
            return father[i]

        def union(x, y):
            x_father, y_father = find_father(x), find_father(y)
            if x_father != y_father:
                father[max(x_father, y_father)] = min(x_father, y_father)

        for swap in allowedSwaps:
            union(swap[0], swap[1])

        groups, res = defaultdict(list), 0
        for i in range(sz):
            groups[find_father(i)].append(i)
        for i in groups.keys():
            cnt = Counter([source[x] for x in groups[i]])
            for idx in groups[i]:
                if target[idx] in cnt and cnt[target[idx]] > 0:
                    cnt[target[idx]] -= 1
                else:
                    res += 1

        return res


if __name__ == "__main__":
    s = Solution()
