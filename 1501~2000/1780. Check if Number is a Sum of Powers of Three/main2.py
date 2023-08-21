"""
Source: https://rb.gy/sx2os
Date: 2023/8/21
Skill:
Ref: https://rb.gy/y9jlg
Runtime: 40 ms, faster than 65.99%
Memory Usage: 16.36 MB, less than 30.96%
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
from functools import cache


class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        if n == 1:
            return True
        if n % 3 == 2:
            return False
        return self.checkPowersOfThree(n // 3)


if __name__ == "__main__":
    s = Solution()

