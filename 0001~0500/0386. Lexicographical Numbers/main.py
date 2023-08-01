"""
Source: https://rb.gy/bvmrk
Date: 2023/8/1
Skill:
Ref:
Runtime: 78 ms, faster than 99.18%
Memory Usage: 22.22 MB, less than 98.53%
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
    def lexicalOrder(self, n: int) -> List[int]:
        res, num = [1], 1
        for _ in range(n - 1):
            if num * 10 <= n:
                num *= 10
                res.append(num)
            else:
                while num % 10 == 9 or num >= n:
                    num //= 10
                num += 1
                res.append(num)
        return res


if __name__ == "__main__":
    s = Solution()
