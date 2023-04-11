"""
Source: https://leetcode.com/problems/removing-stars-from-a-string/
Date: 2023/4/11
Skill:
Ref:
Runtime: 371 ms, faster than 19.47%
Memory Usage: 15.5 MB, less than 89.52%
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


class Solution:
    def removeStars(self, s: str) -> str:
        pos, star_num, res = len(s) - 1, 0, ""
        while pos >= 0:
            if s[pos] == "*":
                star_num += 1
            elif star_num > 0:
                star_num -= 1
            else:
                res += s[pos]
            pos -= 1
        return res[::-1]


if __name__ == "__main__":
    s = Solution()
