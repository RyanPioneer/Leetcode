"""
Source: https://leetcode.com/problems/naming-a-company/
Date: 2023/2/9
Skill:
Runtime: 705 ms, faster than 76.9%
Memory Usage: 28.6 MB, less than 58.70%
Time complexity:
Space complexity:
Constraints:
    2 <= ideas.length <= 5 * 10^4
    1 <= ideas[i].length <= 10
    All the strings in ideas are unique.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        head2string, res = [set() for _ in range(26)], 0
        for idea in ideas:
            head2string[ord(idea[0]) - ord("a")].add(idea[1:])

        for i in range(26):
            for j in range(i+1, 26):
                dup = 0
                for string in head2string[i]:
                    if string in head2string[j]:
                        dup += 1
                res += (len(head2string[i])-dup)*(len(head2string[j])-dup)*2

        return res


if __name__ == "__main__":
    s = Solution