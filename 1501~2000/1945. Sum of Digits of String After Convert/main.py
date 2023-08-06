"""
Source: https://rb.gy/ehv3i
Date: 2023/8/6
Skill:
Ref:
Runtime: 38 ms, faster than 97.06%
Memory Usage: 16.3 MB, less than 77.98%
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
    def getLucky(self, s: str, k: int) -> int:
        nums, res = [], 0
        for c in s:
            nums.append(ord(c) - ord("a") + 1)
        for num in nums:
            res += num // 10 + num % 10
        for _ in range(k - 1):
            if res < 10:
                return res
            string = str(res)
            res = 0
            for c in string:
                res += ord(c) - ord("0")
        return res


if __name__ == "__main__":
    s = Solution()
