"""
Source: https://rb.gy/ea1ij
Date: 2023/8/10
Skill:
Ref:
Runtime: 38 ms, faster than 84.56%
Memory Usage: 16.36 MB, less than 42.65%
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
    def minFlips(self, a: int, b: int, c: int) -> int:
        bit_a, bit_b, bit_c, res = bin(a)[2:], bin(b)[2:], bin(c)[2:], 0
        len_a, len_b, len_c = len(bit_a), len(bit_b), len(bit_c)
        sz = max(len_a, len_b, len_c)
        for i in range(sz):
            num = 0
            if i < len_c:
                num_c = int(bit_c[len_c - 1 - i])
            else:
                num_c = 0
            if i < len_a:
                num += int(bit_a[len_a - 1 - i])
            if i < len_b:
                num += int(bit_b[len_b - 1 - i])
            if num_c == 0 and num > 0:
                res += num
            elif num_c == 1 and num == 0:
                res += 1
        return res


if __name__ == "__main__":
    s = Solution()
