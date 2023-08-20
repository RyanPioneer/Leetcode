"""
Source: https://rb.gy/kiez3
Date: 2023/8/20
Skill:
Runtime: 72 ms, faster than 100.00%
Memory Usage: 17.03 MB, less than 100.00%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def numberOfBeautifulIntegers(self, low: int, high: int, k: int) -> int:
        @cache
        def dfs(length, is_same, diff, rem, target):
            if length == 0:
                if diff == 0 and rem == 0:
                    return 1
                else:
                    return 0
            num = 0
            if not is_same:
                for i in range(10):
                    num += dfs(length - 1, is_same, diff + (i % 2 == 0) * 2 - 1, (rem * 10 + i) % k, target)
            else:
                digit = int(target[-length])
                for i in range(digit):
                    num += dfs(length - 1, not is_same, diff + (i % 2 == 0) * 2 - 1, (rem * 10 + i) % k, target)
                num += dfs(length - 1, is_same, diff + (digit % 2 == 0) * 2 - 1, (rem * 10 + digit) % k, target)
            return num

        def helper(target):
            string = str(target)
            sz, length, total = len(string), 2, 0
            while length < sz:
                for i in range(1, 10):
                    total += dfs(length - 1, False, (i % 2 == 0) * 2 - 1, i % k, "")
                length += 2
            if length == sz:
                digit = int(string[0])
                for i in range(1, digit):
                    total += dfs(length - 1, False, (i % 2 == 0) * 2 - 1, i % k, "")
                total += dfs(length - 1, True, (digit % 2 == 0) * 2 - 1, digit % k, string[1:])
            return total

        return helper(high) - helper(low - 1)


if __name__ == "__main__":
    s = Solution()
