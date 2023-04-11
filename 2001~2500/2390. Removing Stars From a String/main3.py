"""
Source: https://leetcode.com/problems/removing-stars-from-a-string/
Date: 2023/4/11
Skill:
Ref:
Runtime: 351 ms, faster than 21.43%
Memory Usage: 16.3 MB, less than 6.45%
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
        pos, star_num, res = len(s) - 1, 0, []
        while pos >= 0:
            if s[pos] == "*":
                star_num += 1
            elif star_num > 0:
                star_num -= 1
            else:
                res.append(s[pos])
            pos -= 1

        return "".join(res[::-1])


if __name__ == "__main__":
    s = Solution()
