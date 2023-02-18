"""
Source: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
Date: 2023/2/18
Skill:
Runtime: 29 ms, faster than 88.6%
Memory Usage: 13.8 MB, less than 97.50%
Time complexity:
Space complexity:
Constraints:
    The returned string must contain only lowercase English letters.
    1 <= n <= 500
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def freqAlphabets(self, s: str) -> str:
        i, sz, res, key2value = 0, len(s), "", defaultdict()
        for j in range(1, 27):
            if j < 10:
                key2value[str(j)] = chr(ord("a") + j - 1)
            else:
                key2value[str(j // 10) + str(j % 10)] = chr(ord("a") + j - 1)
        while i < sz:
            if i < sz - 2 and s[i + 2] == "#":
                res += key2value[s[i:i + 2]]
                i += 3
            else:
                res += key2value[s[i]]
                i += 1

        return res


if __name__ == "__main__":
    s = Solution