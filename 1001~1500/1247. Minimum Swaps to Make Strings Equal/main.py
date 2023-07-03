"""
Source: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
Date: 2023/7/3
Skill:
Ref:
Runtime: 52 ms, faster than 25.88%
Memory Usage: 16.3 MB, less than 78.24%
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
    def minimumSwap(self, s1: str, s2: str) -> int:
        x_num, y_num, res = 0, 0, 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                if s1[i] == "x":
                    x_num += 1
                else:
                    y_num += 1
        while x_num >= 2:
            res += 1
            x_num -= 2
        while y_num >= 2:
            res += 1
            y_num -= 2
        if x_num == 0 and y_num == 0:
            return res
        elif x_num == 1 and y_num == 1:
            return res + 2
        else:
            return -1


if __name__ == "__main__":
    s = Solution()
