"""
Source: https://leetcode.com/problems/optimal-partition-of-string/
Date: 2023/4/4
Skill:
Runtime: 241 ms, faster than 13.85%
Memory Usage: 14.6 MB, less than 47.10%
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
    def partitionString(self, s: str) -> int:
        res, sz, char2freq = 1, len(s), defaultdict(int)
        for i in range(sz):
            if char2freq[s[i]] == 1:
                res += 1
                char2freq.clear()
            char2freq[s[i]] += 1
        return res


if __name__ == "__main__":
    s = Solution()
