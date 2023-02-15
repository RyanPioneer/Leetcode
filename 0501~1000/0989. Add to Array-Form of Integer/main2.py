"""
Source: https://leetcode.com/problems/add-to-array-form-of-integer/
Date: 2023/2/15
Skill:
Runtime: 300 ms, faster than 82.81%
Memory Usage: 15 MB, less than 85.98%
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
        sz, carry, res = len(num), 0, []
        for i in range(sz-1, -1, -1):
            res.append((k%10+num[i]+carry) % 10)
            carry = (k%10+num[i]+carry) // 10
            k //= 10

        while k > 0 or carry > 0:
            res.append((k % 10 + carry) % 10)
            carry = (k % 10 + carry) // 10
            k //= 10

        return reversed(res)


if __name__ == "__main__":
    s = Solution