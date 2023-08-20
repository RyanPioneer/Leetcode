"""
Source: https://rb.gy/m8upc
Date: 2023/8/20
Skill:
Runtime: 63 ms, faster than 100.00%
Memory Usage: 16.29 MB, less than 50.00%
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
    def isAcronym(self, words: List[str], s: str) -> bool:
        if len(words) != len(s):
            return False
        for i in range(len(words)):
            if words[i][0] != s[i]:
                return False
        return True


if __name__ == "__main__":
    s = Solution()
