"""
Source: https://leetcode.com/problems/goal-parser-interpretation/
Date: 2023/2/17
Skill:
Runtime: 29 ms, faster than 81.29%
Memory Usage: 13.8 MB, less than 93.82%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def interpret(self, command: str) -> str:
        res, i, sz = "", 0, len(command)
        while i < sz:
            if command[i] == "G":
                res += "G"
                i += 1
            else:
                if command[i+1] == ")":
                    res += "o"
                    i += 2
                else:
                    res += "al"
                    i += 4

        return res


if __name__ == "__main__":
    s = Solution