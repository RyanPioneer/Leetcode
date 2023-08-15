"""
Source: https://rb.gy/bmapn
Date: 2023/8/15
Skill:
Ref:
Runtime: 42 ms, faster than 75.07%
Memory Usage: 16.00 MB, less than 99.96%
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
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        s, one_bit_num = bin(n)[2:], 0
        for c in s:
            if c == "1":
                one_bit_num += 1
                if one_bit_num > 1:
                    return False
        return True


if __name__ == "__main__":
    s = Solution()

