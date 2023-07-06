"""
Source: https://rb.gy/251gl
Date: 2023/7/6
Skill:
Ref:
Runtime: 2481 ms, faster than 75.76%
Memory Usage: 49.2 MB, less than 48.48%
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
    def groupStrings(self, words: List[str]) -> List[int]:
        father, mydict = [i for i in range(len(words))], defaultdict(int)
        states = [0 for _ in range(len(words))]

        def find_father(i):
            if father[i] != i:
                father[i] = find_father(father[i])
            return father[i]

        def union(i, j):
            father_i, father_j = find_father(i), find_father(j)
            if father_i != father_j:
                f, s = min(father_i, father_j), max(father_i, father_j)
                father[s] = f

        for i in range(len(words)):
            state = 0
            for j in range(len(words[i])):
                c = ord(words[i][j]) - ord("a")
                state |= (1 << c)
            states[i] = state
            if state not in mydict:
                mydict[state] = i
            else:
                union(i, mydict[state])

        for i in range(len(words)):
            for j in range(26):
                if (states[i] & (1 << j)) == 0:
                    continue
                new_state = (states[i] - (1 << j))
                if new_state not in mydict:
                    mydict[new_state] = i
                else:
                    union(i, mydict[new_state])

        group, max_group_size, group_num = defaultdict(int), 0, 0
        for i in range(len(words)):
            group[find_father(i)] += 1
        for key, value in group.items():
            group_num += 1
            max_group_size = max(max_group_size, value)
        return [group_num, max_group_size]


if __name__ == "__main__":
    s = Solution()
    words = ["a", "b", "ab", "cde"]
    res = s.groupStrings(words)
    print(res)
