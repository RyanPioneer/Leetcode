"""
Source: https://leetcode.com/problems/add-to-array-form-of-integer/
Date: 2023/2/15
Skill:
Runtime: 922 ms, faster than 14.37%
Memory Usage: 14.9 MB, less than 85.98%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^4
    0 <= num[i] <= 9
    num does not contain any leading zeros except for the zero itself.
    1 <= k <= 10^4
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        number, cur, sz, res = 0, 1, len(num), []
        for i in range(sz - 1, -1, -1):
            number += num[i] * cur
            cur *= 10

        number += k
        cur = 10
        while number > 0:
            res.append(number % cur)
            number //= 10

        return reversed(res)


if __name__ == "__main__":
    s = Solution